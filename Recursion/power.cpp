#include<iostream>
using namespace std;

int power(int a, int n){

    //time complexity : O(n)
    //space complexity : O(n)
    //a^n = a.a^(n-1);

    //base case 
    if (n==0)   return 1;

    //rec case
    return a*power(a, n-1);
}

int powerOptimised(int a, int n){

    //time complexity : O(logN)
    //base case
    if(n==0)    return 1;

    //rec case
    if(n%2==0){
        return powerOptimised(a*a, n/2);
    }
    else{
        return a*powerOptimised(a*a, n/2);
    }
}

int main(){
    int a = 2;
    int n = 10;
    cout<<power(2, 10)<<endl;
    cout<<powerOptimised(2, 10)<<endl;
}