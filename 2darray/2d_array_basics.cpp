#include<iostream>

using namespace std;

/*
    Note : in memory everything needs to be linearized.
    one of two ways used : 1. Row Major, 2. Column Major.
    how it is stored depends on system architecture but row major is common.
*/



//passed by reference
void print2dArray(int arr[][100], int n, int m){
    // passing number of rows is optional but passing number of columns is mandatory.
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    //Declaration of a 2d array
    int arr[100][100];
    int n, m;

    //input number of rows & columns
    cin>>n>>m;

    //input values of the 2d matrix
    for(int i = 0; i<n; i++){
        for(int j = 0; j < m ; j++){
            cin>>arr[i][j];
        }
    }

    //output using external function
    print2dArray(arr, n, m);


    return 0;
}