#include<iostream>

using namespace std;

string spell[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

void printSpell(int n){
    //base case
    if(n==0){
        return;
    }

    int last_digit = n%10;
    printSpell(n/10);
    cout<<spell[last_digit]<<" ";
}

int main(){
    int n = 2022;
    printSpell(n);
}