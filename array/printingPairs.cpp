//Learning : Nested for loops.
//Time Complexity : O(n^2)
//Space Complexity : O(1)
//For printing All subarrays, time complexity will be O(n^3).

#include<iostream>
using namespace std;

void printAllPairs(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            cout<<"("<<arr[i]<<", "<<arr[j]<<")"<<endl;
        }
        cout<<endl;
    }
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(int);

    printAllPairs(arr, n);
}