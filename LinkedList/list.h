//We are trying to create a replica of the STL "List" while implementing linked list.
#include<iostream>
using namespace std;
//Forward Declaration 
class List;

class Node{
    //each node will contain some data (in this case, int) and a pointer that stores the address of the next node (hence the datatype Node*).
    int data;

public:
    //in order to access the next address from the main, we need to make it public
    Node * next;
    //Constructor

    //This type of value initialisation is called initialisation method, when values are defined in paranthesis, it's called assignment method.
    Node(int d): data(d), next(NULL){}

    //since data is a private member of class List, so as to fetch this from main
    int getData(){
        return data;
    }


    friend class List;

    //deleting a node - NOTE THAT THIS IS A RECURSIVE DESTRUCTOR CALL
    ~Node(){
        if(next != NULL){
            delete next;
        }
        cout<<"Deleting the node with data "<<data<<endl;
    }
};

class List{
    //each list will contain a head pointer of the type Node* that will just point to the First Node.
    //For ease of use, we will also create a Tail pointer to store the last node.

    Node * head;
    Node * tail;


    int searchHelper(Node * start, int key){
        //base case
        if(start == NULL)
            return -1;
        
        //value matches, return 0;
        if(start->data == key) 
            return 0;
        
        int subIdx = searchHelper(start->next, key);
        if(subIdx == -1){
            return -1;
        }
        return subIdx + 1;
    }

public:
    //Constructor
        //whenever the linkedlist is initialised, the head and tail pointers both should point to NULL
    List(): head(NULL), tail(NULL){}

    //Methods

        //since head is a private member of class List, so to fetch this from main
    Node* begin(){
        return head;
    }

        //push_front
    void push_front(int data){
        //Case 1 : List is empty
        if(head == NULL){
            //we have to dynamically allocate a new memory to the node so that the NODE STAYS EVEN AFTER THE FUNCTION CALL IS OVER. hence we create a pointer of datatype Node that points to this newly created Node, by calling it's constructor
            Node * n = new Node(data);
            head = tail = n;
            return;
        } 

        //Case 2 : List not empty
            //create a Node * pointer that points to the newly created Node, now point it's "next" to head, and then head points to this newly created node.
            //NOTE THAT n IS A LOCAL VARIABLE AND IT WILL GET DESTROYED AFTER THE FUNCTION CALL IS OVER
        Node * n = new Node(data);
        n->next = head;         //creating the link
        head = n;               //re-addressing the head pointer
        return;
    }


        //push_back
    void push_back(int data){
        //Case 1 : list empty
        if(head == NULL){
            Node *n = new Node(data);
            head = tail = n;   
            return;
        }

        //Case 2 : List not empty
        Node *n = new Node(data);
        tail->next = n;         //creating the link
        tail = n;               //re-addressing the tail pointer.
        return;
    }


        //insert at a specific position
    void insert(int data, int pos){
        if(pos == 0){
            push_front(data);
            return;
        }
        //Otherwise

        //we need the access of the node after which we need to insert the new node
        Node * temp = head;
        for(int jump = 1; jump<= pos - 1; jump++){
            temp = temp->next;
        }

        Node * n = new Node(data);

        //first create the new connection, then break the old connection
        n->next = temp->next;
        temp->next = n;
    }

        //search inside a linked list
    int search(int key){
        int idx = 0;

        Node *temp = head;
        while(temp->next != NULL){
            if(temp->data == key){
                return idx;
            }
            idx++;
            temp = temp->next;
        }
        return -1;
    }

        //recursive search
    int recursiveSearch(int key){
        //since we also need to pass the head to search recursively, we need to use a helper function here.
        int idx = searchHelper(head, key);
        return idx;
    }

        //pop Front
    void pop_front(){
        Node * temp = head;
        head = head->next;
        temp->next = NULL;      //doing this so that even if destructor is called it should not affect the rest of the linked list
        delete temp;
    }

        //pop Back
    void pop_back(){
        Node * iterator = head;
        while (iterator->next->next != NULL) {
            iterator = iterator->next;
        }
        tail = iterator;
        delete tail->next;
        tail->next = NULL;
    }

        //remove
    void remove(int pos){
        Node * temp = head;
        for(int jump = 1; jump <= pos - 1; jump++){
            temp = temp->next;
        }
        Node * n = temp->next;
        temp->next = n->next;
        n->next = NULL;
        delete n;
    }
    //deleting the entire linkedlist
    ~List(){
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }
};


/*
    Why are we using -> ?
    Suppose we have an object of a class. We can access it's properties using obj.property_name.
    But in this case 'n' is a pointer of type Node *, and it is pointing to the object of the Node class.
    So, in order to get the object, we will have to first de-reference the pointer as (*n).property_name to access the same property.

    Thus, to directly access a property from the pointer, we can use -> operator.
*/