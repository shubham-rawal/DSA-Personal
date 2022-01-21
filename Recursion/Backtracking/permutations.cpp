/*
    Permutations : goal is to find all possible permutations of a string and print them.
    Idea is to swap the first letter of the string with the elements of the string in each iteration and then find the permutations of the smaller subproblem.

    Backtracking thing : since the output array would be passed by reference, the actual array would change when swapping the 1st and 2nd element. thus, we need to swap it back in that case.

    NOTE : REFER TO SS IN NOTES FOR LOGIC. Dry run code for clarity.
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void findPermutations(char *input, int n, int i, vector<string> &ans){
    //base case
    if(i == n){
        ans.push_back(input);
        return;
    }

    //rec case
    for(int idx = i; idx < n; idx++){
        swap(input[i], input[idx]);
        findPermutations(input, n, i+1, ans);
        swap(input[i], input[idx]);
    }

}

int main(){
    char input[100];
    int n;
    cin>>n;
    cin>>input;

    vector<string> ans;

    findPermutations(input, n, 0, ans);

    for(auto s : ans){
        cout<<s<<endl;
    }

}