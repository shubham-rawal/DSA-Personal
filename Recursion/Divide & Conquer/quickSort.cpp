/*
    Another D&C sorting technique. 
    Here, we do 3 simple steps.

    1. Choose a Pivot element -- usually chosen as the last element.
    2. Move the elements in such a way that 2 windows are created. 
        ______(<)______ pivot _____(>)_____ such that the pivot element is at its correct position.

    3. Recursively sort the left and right elements..

    Basically what we do is just in each recursive iteration, we just place the pivot element to it's correct position.

    NOTE : REFER TO SS IN NOTES FOR LOGIC
    
*/
#include<iostream>
#include<vector>
using namespace std;


int partition(vector<int> &arr, int s, int e){
    int pivot = arr[e];
    int i = s-1;

    for(int j = s; j<e; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[e]);

    return i + 1;
}

void quickSort(vector<int> &arr, int s, int e){
    //Base case
    if(s>=e)    return;

    //rec case
    int p = partition(arr, s, e);

    // now since we have the pivot element's index and we know that the pivot element is correctly placed, we have to sort the left and right parts.

    //left
    quickSort(arr, s, p-1);
    //right
    quickSort(arr, p+1, e);

}
int main(){
    vector<int> arr = {10, 5, 2, 0, 7, 6, 4};
    int s = 0;
    int e = arr.size() - 1;

    quickSort(arr, s, e);

    for(int i = s; i<=e; i++){
        cout<<arr[i]<<" ";
    }
}