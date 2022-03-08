#include<iostream>
#include<stack>
using namespace std;

//Challenge : Reverse stack using recursion


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

//Reversing a stack : approach is very simple : first we remove the top element, then we reverse the smaller stack, then we add the top element to the bottom of the stack.
void reverse(stack<int> &s){
    //base case
    if(s.empty())   return;

    //rec case
    int t = s.top();
    s.pop();

    reverse(s);
    insertAtBottom(s, t);

}


int main(){
    stack<int> s;
    s.push(1); 
    s.push(2);
    s.push(3);
    s.push(4);


    reverse(s);


    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}