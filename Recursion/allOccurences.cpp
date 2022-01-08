#include<iostream>
#include<vector>

using namespace std;

//Given a vector and a key, you need to store all the occurences of the key in a vector. Return this vector

void helper(int key, vector<int> v, int i, vector<int> &ind){
    //base case
    if(i == v.size())
        return;
    if(v[i] == key)
        ind.push_back(i);
    helper(key, v, i+1, ind);
}

vector<int> findAllOccurences(int k, vector<int> v){
    vector<int> ind;
    helper(k, v, 0, ind);
    return ind;
}
int main(){
    vector<int> arr = {1, 2, 2, 2, 3, 5, 6, 2, 0, 1};
    int k = 2;
    vector<int> ans = findAllOccurences(k, arr);
    for(int i = 0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}