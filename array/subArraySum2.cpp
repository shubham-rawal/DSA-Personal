/*
    1. Brute Force Approach 
    2. Prefix Sum Approach <---------------------Time Complexity : O(n^2)
    3. Kadane's Algorithm (imp)
*/

#include<iostream>

using namespace std;
//Approach is to create another array of size n that stores the cumulative sum of all the elements in the array upto that point.
/*
This way, the subarray sum of elements from index i till j can be calculated as : 
    ps[j] - ps[i-1];
*/

int prefixSumofSubArraySum(int arr[], int n){

    //Creating the prefix sum array.
    int prefix[n];
    prefix[0] = arr[0];

//The prefix sum array has thus been created in O(n) time.
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

//The required subArray sum has thus been calculated in just O(n^2) time.
    for(int i = 0; i< n; i++){
        for(int j = i; j < n; j++){
            if(i>0)
                cout<<"Sum of elements from "<<i<<"to "<<j<<" is : "<<prefix[j] - prefix[i-1]<<endl;
            else cout<<"Sum of elements from "<<i<<"to "<<j<<" is : "<<prefix[j]<<endl;
        }
    }

}
int main(){
    int arr[] = {-2, 3, 0, 5, 6, -7, 8, 1};
    int n = sizeof(arr)/sizeof(int);

    prefixSumofSubArraySum(arr, n);
    
}

