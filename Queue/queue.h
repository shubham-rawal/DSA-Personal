//Implementation of a Queue data structure using an array of fixed size, which is input by the user.

class Queue{

    //since we do not know the size of the fixed array, we use a pointer to the array
    int *arr;
    int cs;
    int ms;
    int front;
    int rear;

public:
    Queue(int default_size = 5){
        ms = default_size;
        cs = 0;
        arr = new int[ms];
        front = 0;
        rear = ms-1;
    }

    //full method
    bool full(){
        return cs==ms;
    }

    //empty method
    bool empty(){
        return cs==0;
    }

    //push method
    void push(int data){
        if(!full()){
            //take the rear to the next index
            rear = (rear+1)%ms;     //since this is a circular queue, we take care of overflow
            arr[rear] = data;
            cs++;
        }
    }


    //pop method
    void pop(){
        if(!empty()){
            //take the front pointer forward
            front = (front+1)%ms;       //same logic 
            cs--;
        }
    }

    //front
    int getFront(){
        return arr[front];
    }
};