#include<iostream>

using namespace std;

void dec(int n){
    if(n==0)    return;
    cout<<n<<", ";
    dec(n-1);

    //All statements executed before recursive calling of the function are done while moving TOWARDS THE BASE CASE. ---> AT CALLING TIME.
}

void inc(int n){
    if(n==0)    return;
    inc(n-1);
    cout<<n<<", ";

    //All statements executed after recursive calling of the function are done while moving AWAY FROM THE BASE CASE. ---> AT RETURN TIME.
}

int main(){
    int n = 5;
    dec(5);
    cout<<endl;
    inc(5);
}

