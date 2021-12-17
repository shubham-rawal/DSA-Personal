/*
    Given an array of integers(sorted) and an integer Val, WAF to return the lower bound of the given array.
    Lower bound is the integer just smaller than the given integer.
*/

//Sidenote = given that the array is sorted, we can use binary search.

#include<iostream>
using namespace std;

int lowerBound(int arr[], int n, int val){
    int s = 0, e = n-1;
    int mid = 0;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid] == val)
            return arr[mid];
        else if(arr[mid]<val)
            s = mid+1;
        else 
            e = mid-1;
    }
    //Now that the loop exits, val is not found in arr, and l>h
    //val is less than all elements in the array.
    if(s==0 && arr[s]>val){
        return -1;
    }

    //A[e] is the element that has the element just smaller than val, hence we return it.
    else 
    return arr[e];
}
int main(){
    int arr[] = {-1, -1, 2, 3, 5};
    int n = sizeof(arr)/sizeof(int);
    int val = 4;
    
    cout<<lowerBound(arr, n, val)<<endl;
}