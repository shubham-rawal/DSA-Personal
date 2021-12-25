#include<iostream>

using namespace std;

// Fast Exponentiation

// trick is to multiply all the set bits of the exponent.

int fast_exponentiation(int a, int n){
    int ans = 1;
    
    while (n>0)
    {
        int last_bit = (n&1);
        if(last_bit){
            ans = ans * a;
        }
        a = a*a;
        n = n>>1;

    }
    return ans;
    

}

int main(){
    int a, n;
    cin>>a>>n;
    cout<<fast_exponentiation(a, n)<<endl;
}