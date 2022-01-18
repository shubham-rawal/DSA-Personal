/*
    In this problem also, we BREAK DOWN THE PROBLEM INTO SIMPLER SUBPROBLEMS. Let's first say that we have just 1 disk. 
    We can easily move this disk from tower A to C in 1 move only.

    Now, let's take 2 disks. First we move uppermost disk from A to B. Then we move the biggest disk from A to C. Then finally, we move the disk from B to C. Hence, we know how to deal with 2 disks.

    For 3, we first want the upper 2 disks to be moved to tower B so that we can move the lowermost disk to tower C. Right?

    We already know how to move 2 disks from one tower to another. 
    Now if there are suppose N disks to be moved from tower A to tower C. 
    
    1. If we first move N-1 upper disks from A to B,
    2. Then move the last disk from tower A to C,
    3. And finally, transfer the n-1 disks from tower B to C

    We have achieved our solution. How to move these N-1 disks? Using recursion. We first then try to move the upper N-2 disks from A to C (since here the final tower is B), for that we move N-3 disks from A to B (since final tower here is C) and so on...
    
    What would be the base case? 1. Since we know how to accomplish that in one statement

    NOTE: REFER TO SS IN NOTES FOR LOGIC.
*/

#include<iostream>
using namespace std;

void towerOfHanoi(int n, int A, int B, int C){
    //n is the number of disks in tower A (starting), B is the intermediate tower (helper) and C is the destination tower

    if(n>0){
        towerOfHanoi(n-1, A, C, B);
        cout<<"Move a disk from "<<A<<" to "<<C<<endl;
        towerOfHanoi(n-1,B, A, C);
    }
}

int main(){
    int n;
    cin>>n;
    int A, B, C;
    cin>>A>>B>>C;

    towerOfHanoi(n, A, B, C);
}