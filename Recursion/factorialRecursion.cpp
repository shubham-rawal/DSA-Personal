#include<iostream>

using namespace std;
//Some notes about recursion
/*
    Recursion takes up extra space as it repeatedly makes use of the call stack for recursively calling smaller 
    breakdowns of the problem until the base case is reached.
    In doing so, memory is also used for storing the results of each smaller iteration. Hence, both Time complexity & Space Complexity in the case of factorial would be :
    O(n)

    The callstack keeps a stack of all the function calls performed during execution of a program, and a function is removed from stack-memory only after it is done executing.
*/

int fact(int n){

    //Base Case
    if(n==0)
        return 1;

    //Breaking down into smaller subproblems
    return n*fact(n-1);
}
int main(){
    int n = 5;
    cout<<fact(n)<<endl;
}