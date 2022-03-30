#include<iostream>
#include "heap.h"
using namespace std;

int main(){
    Heap h = Heap(10, false);
    h.push(10);
    h.push(8);
    h.push(4);
    h.push(9);
    h.push(12);
    h.push(16);
    h.push(17);
    h.push(18);
    h.push(2);

    cout<<h.top();
}