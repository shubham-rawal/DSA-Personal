#include<iostream>

using namespace std;

int convertToBinary(int n){
    int pow = 1;
    int ans = 0;
    while(n>0){
        int last_bit = (n&1);
        ans += last_bit*pow;
        pow*=10;
        n = n>>1;
    }    
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<convertToBinary(n)<<endl;
}