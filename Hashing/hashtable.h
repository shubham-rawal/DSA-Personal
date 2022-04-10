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
        cs = 0;
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

    //Insert
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


    //Search
        //the return type is T* because there might be a possibility that the object may not be present. In that case we should return NULL, but in case the object is found, we return the address to that object.
    T* search(string key){
        int idx = hashFn(key);

        Node<T> *temp = table[idx];

        while(temp!=NULL){
            if(temp->key == key){
                return &temp->value;
            }
            temp = temp->next;
        } 
        return NULL;
    }

    //Erase
    //TODO: Optimize this code for better efficiency
    void erase(string key){
        //if key does not exist in the hashtable
        if(!search(key)){
            cout<<"key does not exist"<<endl;
            return;
        }

        //if key exists
        int idx = hashFn(key);
        Node<T> *temp = table[i];

        //3 cases
            //head of the linked list;
        if(temp->key == key){
            table[i] = temp->next;
            delete temp;
            return;
        }

            //end of the linked list
        while(temp->next->next!=NULL) temp = temp->next;
        if(temp->next->key == key){
            delete temp->next;
            temp->next = NULL;
            return;
        }

            //middle of the linked list
        while(temp->next->key != key)   temp = temp->next;
        Node<T> * t2 = temp->next;
        temp->next = t2->next;
        delete t2;
        return;
    }


    //operator overload  ---- IMPORTANT
    /*
        Since we want the functionality of h["mango"] = 100, i.e. the value of the bucket would be in main and we need to update it here, we can change the return type of the overload function to return the "value" by reference. In this way, the value address is RETURNED by reference and thus, we can easily set it inside main
    */
    T& operator[](string key){
        //return the value by reference
        //if key is not found then create a new node and return
        //return the existing node
        T* valueFound = search(key);
        if(valueFound == NULL){
            //initially, this object will contain garbage but it doesn't matter as it is going to be updated anyways.
            T object;
            insert(key, object);
            //to check where it has been created, we call the search function again
            valueFound = search(key);
        } 

        //since the valueFound is the address of the value returned from the search function, we deference it to pass this value as a reference again as a return type of this operator function 
        return *valueFound; 
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