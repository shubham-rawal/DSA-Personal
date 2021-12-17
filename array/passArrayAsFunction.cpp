//Learning : Arrays are passed by Reference inside functions.

#include<iostream>

using namespace std;


//We will create a function to print the array.
void printArray(int arr[], int n){


//Note: Arrays are passed to any function as reference. So it's not the array that is being passed, it is the pointer pointing to the address of the array that is being passed.
//A pointer has a size of 8 bytes.

//Therefore, we need to pass the size of the array as a parameter as well.
    cout<<"In Function :"<<sizeof(arr)<<endl;
    arr[0] = 100;
    cout<<"Printing from function : "<<endl;
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;

}
int main(){

int arr[] = {1, 2, 3, 4, 5, 6};

//total memory occupied by the array divided by memory occupied by single element will give us no. of elements of the array. 
int n = sizeof(arr)/sizeof(int);

cout<<"In Main :"<<sizeof(arr)<<endl;

printArray(arr, n);


cout<<"Printing from Main"<<endl;
for(int i = 0; i<n;i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;

    return 0;
}