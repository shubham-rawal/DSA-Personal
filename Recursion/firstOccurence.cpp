#include<iostream>

using namespace std;

int firstOccurence(int arr[], int n, int key){
    //base case
    if(n==0){
        //end of array, element not found.
        return -1;
    }
    //rec case
    if(arr[0] == key)
        return 0;

    int subIndex = firstOccurence(arr+1, n-1, key);
    if(subIndex != -1){
        return subIndex + 1;
    }
    return -1;
}

int lastOccurence(int arr[], int n, int key){
    //base case
    if(n==0)
        return -1;
    
    //rec case
    int subIndex = lastOccurence(arr+1, n-1, key);
    if(subIndex == -1){
        if(arr[0] == key)
            return 0;
        return -1;
        }
    else{
        return subIndex+1;
    }
}
int main(){
    int arr[] = {1,2 ,3, 4, 5, 2, 7};
    int n = sizeof(arr)/sizeof(int);

    cout<<last Occurence(arr, n, 2)<<endl;
}