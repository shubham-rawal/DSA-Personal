//Implement a stack class using 2 queues internally as a Data Structure.
#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q1, q2;

public:
    // Stack();


    //empty
    bool empty(){
        return (q1.empty() and q2.empty());
    }

    //push
    void push(int d){
        //insert into the non empty queue
        if(!q1.empty()){
            q1.push(d);
        }
        else    q2.push(d);
    }


    //pop
    void pop(){
        if(q1.empty()){
            //shift the elements from q2 to q1
            while(!q2.empty()){
                int front = q2.front();
                q2.pop();

                if(q2.empty()){
                    break;      //so that the last element in the queue is not shifted to q1
                }
                q1.push(front);
            }
        }
        else{
            //exact complimentary case
            while(!q1.empty()){
                int front = q1.front();
                q1.pop();

                if(q1.empty()){
                    break;
                }

                q2.push(front);
            }
        }
    }


    //top
    int top(){
        if(q1.empty()){
            //shift the elements from q2 to q1
            while(!q2.empty()){
                int front = q2.front();
                q2.pop();   
                q1.push(front);
                if(q2.empty()){
                    return front;
                }
            }
        }

        else{
            //exact complimentary case
            while(!q1.empty()){
                int front = q1.front();
                q1.pop();
                q2.push(front);
                if(q1.empty()){
                    return front;
                }
            }
        }
        return -1;
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    s.pop();
    s.push(6);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}