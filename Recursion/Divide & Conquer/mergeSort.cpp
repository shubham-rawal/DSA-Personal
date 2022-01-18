/*
    Idea is to divide the array into 2 halves, sort these 2 halves individually (recursively by further dividing into 2 halves until each half has just 1 element left) and then merging these two halves together. 

    For eg, we have the unsorted array : 5 2 4 0 7 6 3 9

    1. Array divided into 2 halves : 5 2 4 0 and 7 6 3 9 
    2. Both these arrays are individually sorted using recursion 
        2.1) Left array 5 2 4 0 further broken down to 2 parts : 5 2 and 4 0.
        2.2) 5 2 broken down to 5 & 2. Now they're already sorted so merged as 2 and 5 (we will write a function for comparision).

    3. The two sorted arrays are merged into a single array. ( we write a seperate function for comparison)

    NOTE: REFER TO SS IN NOTES FOR LOGIC.  
*/

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> & array, int s, int e){
    //here we accept the entire array but we can divide it into 2 parts here
    int i = s;
    int m = (s+e)/2;
    int j = m + 1;

    //we create a temp array to store the merged result.
    vector<int> temp;

    //while we have elements in both the regions to compare, we continue
    while(i<=m and j<=e){
        if(array[i] < array[j]){
            temp.push_back(array[i++]);
        }
        else
            temp.push_back(array[j++]);
    }

    //when one of these subarrays is exhausted, we can directly put in remaining values of the other subarray as it's already sorted.

    //copy remaining elements from 1st subarray
    while(i<=m){
        temp.push_back(array[i++]);
    }

    //or copy remaining elements from 2nd subarray
    while(j<=e){
        temp.push_back(array[j++]);
    }

    //now we need to copy back all elements from temp array to original array to reflect back changes in the actual temp array.
    int k = 0;

    for(int idx = s; idx<=e; idx++){
        array[idx] = temp[k++];
    }
    return;
}

void mergeSort(vector<int> &arr, int s, int e){
    //base case
    if(s>=e)    return;

    //rec case
    int mid = (s+e)/2;
        //sorting the left part
    mergeSort(arr, s, mid);
        //sorting the right part
    mergeSort(arr, mid+1, e);
        //merging the two sorted parts together
    merge(arr, s, e);
}

int main(){
    vector<int> arr = {10, 5, 2, 0, 7, 6, 4};

    int s = 0;
    int e = arr.size() - 1;
    mergeSort(arr, s, e);
    for(int i = 0 ; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}