/*
    1. Brute Force Approach <-------------------Time = O(n^3)
    2. Prefix Sum Approach
    3. Kadane's Algorithm (imp)
*/

#include<iostream>
using namespace std;

int bruteForceLargestSum(int arr[], int n){
    int sum = 0;
    int largestSum = INT_MIN;

    int startIndex = 0, endIndex = 0;

    for(int i = 0; i<n;i++){
        for(int j = i; j<n; j++)
        {
            sum = 0;
            for(int k = i; k<=j; k++){
                sum +=arr[k];
            }
            cout<<"sum of subarray starting from "<<i<< "to "<<j<<" is : "<<sum<<endl;
            if(sum > largestSum){
                largestSum = sum;
                startIndex = i;
                endIndex = j;
            }
        }
    }
    cout<<"Largest sum in all subarrays is : "<<largestSum<<" from index "<<startIndex<<" to "<<endIndex<<endl;

    return 0;
}


int main(){
    int arr[] = {-2, 3, 0, 5, 6, -7, 8, 1};
    int n = sizeof(arr)/sizeof(int);

    bruteForceLargestSum(arr, n);

    

}