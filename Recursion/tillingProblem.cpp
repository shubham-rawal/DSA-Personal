/*
    Given a 4*n board and tiles of size 4*1, count the number of ways to tile the given board using the tiles.
    You can tile the board both horizontally and vertically.
*/

#include<iostream>
using namespace std;

int noOfWays(int n){
    //base case
    if(n<=3)
        return 1;
    return noOfWays(n-1) + noOfWays(n-4);
}

int main(){}