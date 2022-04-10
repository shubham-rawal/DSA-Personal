//File : Hashtable test

#include<iostream>
#include"hashtable.h"

using namespace std;

int main(){
    Hashtable<int> h;
    h.insert("Mango", 100);
    h.insert("Apple", 235);
    h.insert("Litchi", 170);
    h.insert("Grapes", 255);

    h.print();

    return 0;
}