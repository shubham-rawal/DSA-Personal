/*
    Count the number of binary strings with no consecutive 1's that may be formed using a binary string of length n.
*/

//Note: Can also be somehow associated with FIBONACCI SERIES, as has the SAME RECURSIVE EQUATION.

#include<iostream>

using namespace std;

//refer to ss in notes to understand logic.

int noOfBinaryStrings(int n){

    //time complexity : O(2^n)

    //time complexity using DP (memoisation) : O(n) <---- store in a freq array just like optimised fibonacci

    //time complexity using MATRIX EXPONENTIATION : O(k^3logN) where k is the number of terms in the recursive equation.

     
    if(n==0 or n==1){
        return n+1;
    }

    //little bit like PnC. (n-1) subProblem is for when we place 0 in the first position, (n-2) subProblem is for when we place 1 in the first position, as we are left with no choice but to place 0 in the next position.
    return noOfBinaryStrings(n-1) + noOfBinaryStrings(n-2);
}

int main(){
    int n = 5;
    // cin>>n;
    cout<<noOfBinaryStrings(n)<<endl;
}
