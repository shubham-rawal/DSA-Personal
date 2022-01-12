#include<iostream>
using namespace std;


//Bubble Sort Algorithm
void bubbleSortRecursive1(int a[], int n){
    //base case
    if(n==1)    return;

    for(int j = 0; j < n - 1; j++){
        if(a[j]>a[j+1])
            swap(a[j], a[j+1]);
    }

    bubbleSortRecursive1(a, n-1);    
}

void bubbleSortRecursive2(int a[], int n, int j){
    
    //idea is to make the inner loop also recursive.

    //base condition for outer loop
    if(n==1)    return;

   //base condition and recursive control for inner loop
   if(j==n-1){
       //reduce the problem size and reset value of j to 0.
       bubbleSortRecursive2(a, n-1, 0);
       return;
   }

    if(a[j]>a[j+1])
        swap(a[j], a[j+1]);
    bubbleSortRecursive2(a, n, j+1);       //this will control the inner loop    
}
int main(){
    int arr[] = {3, 5, 7, 2, 4, 1, 9, 0};   //the unsorted array.
    int n = sizeof(arr)/sizeof(int);
    cout<<"Unsorted array is : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //the sort function accepts another function as an optional parameter that is used to define the order of the sorting(ascending or descending).
    bubbleSortRecursive2(arr, n, 0);


    cout<<"Sorted array is : "<<endl;
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}