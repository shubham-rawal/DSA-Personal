#include<iostream>
#include "stackV.h"
using namespace std;

int main(){
    Stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    S.push(6);
    S.push(7);
    S.push(8);
    S.push(9);


    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
}