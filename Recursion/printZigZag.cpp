/*
    This example demonstrates how the call stack works with multiple recursive calls
    Given a number, we are required to print the following pattern

    n = 1;
    111

    n = 2;
    211121112

    n = 3
    321112111232111211123

    basically for multiple recursive calls,  three types of regions exist. (unlike a single recursive call where only call time and return time exist).
    pre 
    in
    post

    It is using multiple recursive calls that the above pattern has been printed.

    NOTE: REFER THE SS IN NOTES TO UNDERSTAND HOW THIS IS REPRESENTED IN A EULER TREE FORMAT.
*/

#include<iostream>
using namespace std;

void pzz(int n){
    //base case
    if(n==0)    return;

    //rec case
    cout<<"Pre "<<n<<endl;
    pzz(n-1);
    cout<<"In "<<n<<endl;
    pzz(n-1);
    cout<<"Post "<<n<<endl;
}

int main(){
    pzz(3);
}