#include<iostream>

using namespace std;

int main(){
    int x = 10;
    float y = 5.5;


    //Printing address of x
    cout<<&x<<endl;

    // cout<<&y<<endl;

    //Demo Pointer
    int * xptr = &x;
    cout<<xptr<<endl;

    //Address of a pointer variable 
    cout<<&xptr<<endl;

    //Pointer to a pointer
    int* *xxptr = &xptr;
    cout<<xxptr<<endl;

    //Dereference Operator *
    //An interesting property of pointers is that they can be used to access the value of the address they point to directly by using * as a dereference operator.
    cout<<"Value stored by pointer xptr is "<<*xptr<<endl;
    cout<<"Value stored by pointer xxptr is "<<*xxptr<<endl;


    //Null pointer
    //Sometimes it's useful to make our pointers point to nothing. This is called a NULL pointer. This address does not actually exist yet so dereferencing it would result in segmentation fault.
    int *p = 0;
    int *q = NULL;

}