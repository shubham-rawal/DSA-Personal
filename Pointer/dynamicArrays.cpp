#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    //Dynamic Array

    // creating a pointer (which is stored in static memory), and "new" keyword allocates memory from the heap memory of 9 units storing the datatype 'int'.
    int *arr = new int [n];
    
    cout<<arr<<endl;

    for(int i = 0; i<n; i++){

        //automatically converted to *(arr + i) by the compiler
        arr[i] = i;
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    delete [] arr;

    cout<<arr<<endl;


    //Below statement is not recommended.
    //cout<<arr[2]<<endl;

    return 0;
    }