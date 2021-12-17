//Given an integer vector and a value k, rotate the array k times clockwise

/*
    Approach : since we're given a vector, we can use direct operations to
    push_back and pop.
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> kRotate(vector<int> a, int k){
     // your code  goes here
    int size = a.size();
    for(int i = 0 ; i < size-k; i++){
        a.push_back(a[i]);
        a.erase(i);
    }
    return a;
}
int main(){
    vector<int> arr = {1, 3, 5, 7, 9};
    int k =2;
    cout<<kRotate(arr, k);

}