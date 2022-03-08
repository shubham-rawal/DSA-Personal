//Implementing Queue data structure using LinkedList
//since this is dynamic, there is no 'full' functionality

class Node{
    int data;
    Node* next;

public:
    Node(int d){
        data = d;
        next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;

public:
    Queue(){
        head = NULL;
        tail = NULL;
    }

    //empty
    bool empty(){
        return head==NULL;
    }

    //push
    void push(int d){
        if(empty()){
            Node* n = new Node(d);
            head = tail = n;
        }
        else{
            Node* n = new Node(d);
            tail->next = n;
            tail = n;
        }
    }

    //pop
    void pop(){
        if(!empty()){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    //front
    int getFront(){
        return head->data;
    }

};
