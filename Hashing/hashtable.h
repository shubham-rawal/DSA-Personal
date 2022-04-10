//File hashtable.h

#include<iostream>
#include<cstring>
using namespace std;

//Node class for the linked lists. (why LinkedLists? for collision handling.)
template <typename T>
class Node{
public:
    string key;
    T value;
    Node * next;

    Node(string key, T value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    //using this recursive destructor, when we delete the ith linked list, we are actually deleting the entire linked list this way and not just its head.
    ~Node(){
        if(next!=NULL)  delete next;
    }
};

//hashtable class
template <typename T>
class Hashtable{
    Node<T> ** table;
    int cs;     //total entries that are present in the table so far
    int ts;     //table size


    //hashFunction : to convert the string key values to an address(int) so as to fetch it in O(1) time on an average.
    int hashFn(string key){
        int idx = 0;
        int power = 1;

        for(auto ch : key){
            idx = (idx + ch*power)%ts;
            power = (power*29)%ts;
        }
        return idx;

    }

    //rehash function : when the cs/ts i.e. load_factor reaches a certain threshold value, we need to double the array and rehash based on the new ts. this is done to ensure that the time complexity is well maintained.
    void rehash(){
        // Save the ptr to the oldTable and we will do insertions in the new table.
        Node<T> **oldTable = table;
        
        int oldTs = ts;

        //increase the table size 
        ts = 2*ts + 1;      //ideally you should make it prime.
        table = new Node<T> *[ts];

        //initialise each of the new head pointers in the new table to NULL, else they would contain garbage
        for(int i = 0; i<ts; i++){
            table[i] = NULL;
        }

        //Copy elements from oldTable to newTable
        for(int i = 0; i<ts; i++){
            Node<T> *temp = oldTable[i];

            while(temp!=NULL){
                string key = temp->key;
                T value = temp->value;

                //since we have already updated the table variable (the class member), all the insertions would happen in the new table
                insert(key, value);
                temp = temp->next;
            }

            //destroy the ith linkedlist
            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }

        //now that we have deleted row by row linked list, we need to delete the whole table now.
        delete [] oldTable;
    }

public:
    //constructor
    Hashtable(int default_size = 7){
        cs = 0;
        ts = default_size;
        table = new Node<T>*[ts];

        for(int i = 0; i<ts; i++){
            table[i] = NULL;
        }
    }

    void insert(string key, T val){
        int idx = hashFn(key);

        Node<T> * n = new Node<T>(key, val);

        //Insertion at the head of the linked list
        n->next = table[idx];
        table[idx] = n;
        float load_factor = cs/(float)ts;

        if(load_factor > 0.7){
            rehash();
        }
    }


    //Printing the hashtable
    void print(){
        //Iterate over the buckets
        for(int i = 0; i<ts; i++){
            cout<<"Bucket "<<i<"->";

            Node<T> *temp = table[i];
            while(temp!=NULL){
                cout<<temp->key<<" -> ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};