#include<iostream>
using namespace std;

//A good example to understand calling time and return time execution.

//First Occurence
int firstOcc(int arr[], int n, int key){

    /*
        Logic:
        since we are looking for the first occurence of an element, we do the following steps.
        1. check if arr[0] is the key.
            case 1 : it is. return 0, as 0th position is the first occurence.
            case 2 : it is not. we move on and consider arr+1 as the new array & repeat this step.
            
            note: incase the arr[0] of any subArray is key, we return 0 as per our logic, else we return -1.
            so we check if subIndex != -1, we return subIndex + 1 (because for each subArray, the actual index will increase by 1).
    */
    //base case
    if(n==0)    return -1;

    //rec case
    if(arr[0] == key)
        return 0;

    //note that here we are performing recursion after checking at arr[0], so arr[0] check is performed at call time.
    int subIndex = firstOcc(arr+1, n-1, key);
    if(subIndex != -1)
        return subIndex + 1;
    return -1;
}

//Last Occurence
int lastOcc(int arr[], int n, int key){

    /*
        Logic:

        Since in this case, we need to find the last occurence of an element, we won't check first if a[0] == key, we will first ask the subproblem if it contains the element we looking for.
        1. Ask the subproblem
            case 1 : it returns -1
                check at current arr[0] if == key?
                    subcase 1: arr[0] == key
                        return 0;
                    subcase 2 : arr[0] != key
                        return -1 so that recursive loop continues
            case 2 : it returns an integer which is not -1(meaning last occurence has been found)
                    return subIndex + 1;
    */



    //base case
    if(n==0)
        return -1;

    //rec case

    //note that here we are first calling the recursive function, so all other lines are executed at return time.
    int subIndex = lastOcc(arr+1, n-1, key);

    if(subIndex == -1){
        if(arr[0] == key)
            return 0;
        else    return -1;
    }
    return subIndex + 1;
}

int main(){
    int arr[] = {1, 2, 2, 2, 3, 4, 7, 4, 1, 4, 2, 0, 7};
    int n = sizeof(arr)/sizeof(int);

    cout<<firstOcc(arr, n, 4)<<endl;
    cout<<lastOcc(arr, n, 4)<<endl;
}