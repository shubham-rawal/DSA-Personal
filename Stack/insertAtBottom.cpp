#include<iostream>
#include<stack>
using namespace std;

//Challenge : Insert given value at the bottom of the stack
void insertAtBottom(stack<int> &s, int val){
    //we will solve this using recursion
    //base case
    if(s.empty()){
        s.push(val);
        return;
    }

    //rec case
    int temp = s.top();
    s.pop();
    
    insertAtBottom(s, val);

    s.push(temp);

}
int main(){
    stack<int> s;
    s.push(1); 
    s.push(2);
    s.push(3);
    s.push(4);


    insertAtBottom(s, 5);


    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }

}