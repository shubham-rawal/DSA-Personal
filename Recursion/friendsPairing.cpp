/*
    Friends Pairing Problem:
    Given N friends who want to go to a party and each of them can remain single or can pair up with another friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
    ----- PnC PROBLEM
*/

//refer to ss in notes for logic
#include<iostream>

using namespace std;

int friendsPairing(int n){
    //base case
    if(n<=1)    return 1;

    int singleWays = friendsPairing(n-1);
    int pairWays = (n-1)*friendsPairing(n-2);

    return singleWays + pairWays;
}

int main(){
    int n = 7;
    cout<<friendsPairing(n)<<endl;
}

 