/*
    The steps executed after the recursive call i.e. on return time is called backtracking. Let's see an example to understand.

    NOTE: Backtracking code is always found after the function call.
*/
#include<iostream>
using namespace std;


void printArray(int arr[], int n){
    for(int i = 0; i<n ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


void fillArray(int arr[], int n, int i, int val){
    //the array is called by reference by default and we will make use of that.
    //base case
    if(i==n){
        printArray(arr, n);
        return;
    }

    //rec case
    arr[i] =  val;
    fillArray(arr, n, i+1, val+1);

    //backtracking step, executed at return time;
    arr[i] = -1*arr[i];
}
int main(){
    int arr[100] = {0};
    int n;
    cin>>n;
    fillArray(arr, n, 0, 1);

    printArray(arr, n);
}