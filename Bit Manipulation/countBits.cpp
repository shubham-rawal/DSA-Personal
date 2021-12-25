#include<iostream>

using namespace std;

int count_bits(int n){

    //LogN complexity because any number would have at most logN bits. (2^4 = 16) and the bits in 16 are 4 + 1 i.e. 5;
    int count = 0;
    while(n>0){
        int last_bit = n&1;
        count += last_bit;

        n = n>>1;
    }
    return count;
}


//Counting Set Bits (faster method)
int count_bits_hack(int n){

    int ans = 0;
    while(n>0){
        //removes the last set bit from the current number
        n = n & (n-1);
        ans++;
    }
    return ans; 
}

int main(){
    //Set bits are the bits that are set to 1.
    // 9 = 1001 ---> 2 set bits
    int n;
    cin>>n;

    cout<<count_bits(n)<<endl;
    cout<<count_bits_hack(n)<<endl;

}