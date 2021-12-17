/*
    1. Brute Force Approach 
    2. Prefix Sum Approach 
    3. Kadane's Algorithm (imp) <---------------------Time Complexity : O(n)
*/

/*
    Approach : we store a running sum while iterating through each element in the array.
                1 , 2, -4, 2, 5, 6, 2, -8, 2, 1, 0
    currentSum: 1   3  0   2  7 13  15  7  9  10 10
    maximumSum: 1   3  3   3  7 13  15  15 15 15 15

    we add each element to the currentSum first, then we check if the current sum is still positive, if yes, we keep it, otherwise we change the currentSum to 0 and start over again.
    we also keep a track of maximumSum to store the maximum SubArray Sum.

    NOTE: This approach won't work if all the elements in the array are negative.
*/
#include<iostream>
#include<cmath>
using namespace std;

int kadanesAlgorithm(int arr[], int n){
    int cs = 0, ms = 0;
    for(int i = 0 ; i < n ; i++){
        cs += arr[i];
        if(cs < 0)  cs = 0;
        ms = max(cs, ms);
    }
    return ms;
}
int main(){
    int arr[] = {1, -1, -1, -1, 3, 4, -1, 8};
    int n = sizeof(arr)/sizeof(int);

    cout<<kadanesAlgorithm(arr, n);

}