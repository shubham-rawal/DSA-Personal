#include<iostream>
#include<vector>

using namespace std;


/*
    Note : for n iterations, we make 1+2+4+8+16+.....nterms calls, which makes the time complexity as O(2^n).
    Space complexity is nothing but the maximum depth of the recursion tree, which is O(n) worst case.

    However, we can reduce redundant calls by storing the values when the calls are made for the first time, thereby reducing the time complexity, but increasing the space usage.
*/
int fib(int n){
    //Recursive equation = f(n) = f(n-1) + f(n-2)

    //For n = 2, we would get the equation f(1) and f(0). But we cannot further breakdown 1 into 0 and -1. Thus, 1 and 0 both would be the base cases.
    if (n==0 or n==1)
        return n;
    return fib(n-1) + fib(n-2);

}

int fibOptimised(int n){
    int vals[n+1];

    for(int i = 0; i<=n; i++){
        vals[i] = -1;
    }

    if(vals[n] == -1){
        if(n==0 or n==1){
            vals[n] = n;
            return n;
        }

        vals[n] = fibOptimised(n-1) + fibOptimised(n-2);
    }

    return vals[n];
}
int main(){
    int n;
    cin>>n;
    cout<<fibOptimised(n)<<endl;
}