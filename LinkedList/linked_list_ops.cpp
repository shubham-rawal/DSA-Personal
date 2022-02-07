#include<iostream>
#include "list.h"

using namespace std;

void printList(List &l){
    Node * temp = l.begin();
    while(temp != NULL){
        cout<<temp->getData()<<" -> ";
        temp = temp->next;
    }    
    cout<<endl;
}

int main(){
    List l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.insert(0, 0);

    printList(l);
    l.reverse();
    printList(l);
     
}