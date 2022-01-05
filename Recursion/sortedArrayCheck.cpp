#include<iostream>

using namespace std;

bool checkForSorted(int arr[], int n){
    //Approach : if(a[0]<a[1] & checkForSorted(remaining array));

    //base case
    if(n==1 or n==0)
        return true;

    //rec case
    if(arr[0]<arr[1] and checkForSorted(arr+1, n-1)){
        return true;
    }
    return false;
}

int main(){
    int arr[] = {1, 2, 3, 4, 7, 6};
    int n = sizeof(arr)/sizeof(int);

    cout<<checkForSorted(arr, n)<<endl;
}