#include<iostream>
#include "list.h"

using namespace std;
void printList(List l){
    Node * head = l.begin();

    while(head != NULL){
        cout<<head->getData()<<" -> ";
        head = head->next;
    }
    cout<<endl;

    head = l.begin();
}


int main(){
    List l;
    l.push_front(1);
    l.push_front(0);
    l.push_back(3);
    l.push_back(4);
    l.insert(2, 2);

    // int idx = l.recursiveSearch(3);
    // cout<<"Element found at idx : "<<idx<<endl;

    printList(l);

    l.pop_back();

    printList(l);
    


    cout<<endl;
    return 0;
}