/*
    Given an array, find its subsets.

    We will just worry about the first element and leave the rest to recursion.
    For the first element, we will have two possible cases : either the element is included in the subset or excluded.

    NOTE: REFER TO SS IN NOTES AND/OR VIDEO FOR LOGIC.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(string a, string b){
    if(a.length() == b.length()){
        return a < b;
    }
    return a.length() < b.length();
}
void findSubsets(char *input, char *output, int i, int j, vector<string> &list){
    //base case
    if(input[i] == '\0'){
        output[j] = '\0';
        string temp(output);
        list.push_back(temp);
    
        return;
    }

    //rec case

    //Including ith element
    output[j] = input[i];
    findSubsets(input, output, i+1, j+1, list);

    //Excluding ith element
        //not updating j so as to override the jth element
    findSubsets(input, output, i+1, j, list);
}

int main(){
    char input[100];
    char output[100];
    vector<string> list;
    cin>>input;

    findSubsets(input, output, 0, 0, list);


    sort(list.begin(), list.end(), compare);
    //since the output array is called by reference, it currently holds the elements of the last possible subset i.e. NULL.
    // hence verifying.

    for(auto s : list){
        cout<<s<<", ";
    }

    return 0; 
}