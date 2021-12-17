/*
    Given a SORTED array and a number x, find the pair in the array whose sum is closest to the given number x;
*/

/*
    Approach : Since the array is sorted, we will take advantage of that.
    Let's say that the array is 
            10  22  28  29  30  40 and x = 54

            just like BINARY SEARCH, we will compute : A[start] + A[end].
            3 possibilities :
            equal ------------> return <A[start], A[end]>
            less -------------> start++
            more -------------> end--

            since compute may not be equal, we will create two variables, currentDifference and diff = INT_MAX;
            currentDifference = abs(compute, x);
            if(currentDifference < diff)
            {
                diff = currentDifference;
                res.first = A[start];
                res.second = A[end];
            }
*/


#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

pair<int, int> closestSum(int A[], int n,int x){
    pair<int, int> res;
    int start = 0, end = n - 1;
    int diff = INT_MAX;
    int currentDiff;


    while(start<end){
        int compute = A[start] + A[end];
        if(compute == x){
            res.first = A[start];
            res.second = A[end];
            return res;
        }
        currentDiff = abs(x-compute);
        if(currentDiff<diff){
            diff = currentDiff;
            res.first = A[start];
            res.second = A[end];
        }
        if(compute < x){
            start++;
        }
        else end--;
    }
    return res;
}
int main(){
    int arr[] = {10, 22, 28, 29, 30, 40};
    int n = sizeof(arr)/sizeof(int);
    int x = 54;
    
    cout<<closestSum(arr, n, x);
}