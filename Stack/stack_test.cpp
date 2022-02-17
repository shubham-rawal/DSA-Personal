#include "stackLL.h"
#include<iostream>
using namespace std;

int main(){
    Stack<char> s;
    s.push('h'); 
    s.push('e');
    s.push('l');
    s.push('l');
    s.push('o');

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }

}