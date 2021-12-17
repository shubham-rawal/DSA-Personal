//Learning : Linear Search
//Time Complexity : O(n)
//Space Complexity : O(1)
#include<iostream>

using namespace std;

int linearSearch(int arr[], int n, int key){

    //iterating through all elements of the array.
    for(int i = 0; i<n; i++)
    {
        //if array element matches key, return
        if(arr[i] == key){
            cout<<"Element found at position : "<<i+1<<endl;
            return 0;
        }
    }
    //if not returned yet, iteration is complete and key not found.
    cout<<"Element not found"<<endl;
    return 0;
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cout<<"Enter the element you wish to search for : ";
    cin>>key;
    linearSearch(arr, n, key);
}