//Time complexity : O(n)
//Space Complexity : O(1) if using single array only.

#include<iostream>
using namespace std;

void reverseArray(int arr[], int n){
    for(int i = 0; i<=n/2;i++)
        swap(arr[i], arr[n-1 - i]);
        //since the last element is at index n-1, we need to swap element at i and element at (n-1) - i.
}
int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Array before reversal is : "<<endl;
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<", ";
    cout<<endl;

    reverseArray(arr, n);

    cout<<"Array after reversal is : "<<endl;
      for(int i = 0; i<n; i++)
        cout<<arr[i]<<", ";
    cout<<endl;


    return 0;
}