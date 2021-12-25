#include<iostream>
using namespace std;


int getIthBit(int n, int i){

    //using the left-shift operator
    int mask = (1<<i);
    return (n&mask) > 0 ? 1 : 0;
}


void setIthBit(int &n, int i){
    /*
                1 0 1
      OR--->    0 1 0    <-------------- (1<<i)
    */
   int mask = (1<<i);

   n = (n|mask);
}

void clearIthBit(int &n, int i){

    /* 
        1 1 0 1
        1 0 1 1      <------- ~ ( 0 1 0 0) <---------- (1<<i)
    */
    int mask = ~(1<<i);
    n = n & mask;
}

void updateIthBit(int &n, int i, int v){

    //first we clear the bit we want to update and then we take an OR with the required bit value.
    clearIthBit(n, i);
    int mask = (v<<i);
    n = n|mask;     //sets the right value
}

void clearLastIBits(int &n, int i){
    int mask = (-1 << i);
    n = n & mask; 
}

void clearBitsInRange(int &n, int i, int j){
    //tricky

    int a = (-1 << j+1);      
         // ~0 is basically -1 as the first bit is signed bit and if it is 1, it is -ve no. stored in  2;s compliment form.
    int b = (1<<i) - 1;         //basically 2^i - 1
    int mask = a|b;
    n = n & mask; 
}
int main(){ 
    int n = 13;
    int i;
    cin>>i;
    // clearIthBit(n, i);

    setIthBit(n, i);
    cout<<n<<endl;
}