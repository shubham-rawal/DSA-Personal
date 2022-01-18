/*
    Given a number, goal is to first print decreasing order, then using the same function print the increasing order.
    For example, printIncDec(3) should print
    3
    2
    1
    1
    2
    3

    we use PMI logic for this problem. for example, for printIncDec(4), we assume that printIncDec(3) is already working, then we fix the base case

    if we output like::

    n
    printIncDec(n-1)
    n

    we get our ans
*/

#include<iostream>
using namespace std;

void printIncDec(int n){
    //base case
    if(n==0)    return;

    //rec case
    cout<<n<<endl;
    printIncDec(n-1);
    cout<<n<<endl;
}

int main(){
    int n;
    cin>>n;
    printIncDec(n);
}