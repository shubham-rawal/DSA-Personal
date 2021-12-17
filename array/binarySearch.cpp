//Learning : Binary Search Algorithm
//          -Works only on sorted array.
//Time Complexity : O(logn)
//Space Compexity : O(1)

/*
    summary ------>
    s = 0, e = n-1;
    while(s<=e){
        find mid;
        do comparison.
            - equal
            - smaller
            - greater
    }
*/

#include<iostream>

using namespace std;

int binarySearch(int arr[], int n, int key){
    int start = 0;
    int end = n-1;
    int mid;
    
    while(start <= end){
        mid = (start+end)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            start = mid+1;
        else 
            end = mid - 1;
    }
    return -1;
}
int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cout<<"enter the element you wish to search :";
    cin>>key;

    int index = binarySearch(arr, n, key);
    if(index == -1)
        cout<<"Element not found"<<endl;

    else if(index!=-1)
        cout<<"Element found at index "<<index<<endl;
    
    return 0;
}