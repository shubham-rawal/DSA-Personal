/*
We are given an array containing n numbers. All numbers are present twice except for one number. Find that unique number without using any extra time/space.
*/

#include<iostream>
#include<vector>

using namespace std;

int xoring(vector<int> v){
    //xor returns 0 only when two both the binary digits are the same.
    int ans = 0;

    for(int i = 0; i<v.size(); i++){
        ans ^= v[i];
    }

    return ans;

}
int main(){
    
}