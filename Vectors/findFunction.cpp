//There are multiple functions inbuilt in STL which can be used for all STL containers, say arrays, vectors, stacks, etc.

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    int key = 6;

    //basically find function is like iterating over the array from the begin to end (both being iterators, end being after the last element & not included, and when the key is found, find returns that iterator(present at that address), which inturn is stored in a datatype of iterator. cout<<it would display the address of the iterator at that position. To get index, we need to subtract base index from it. If the iterator reaches the end, it means that the element was not found. Basically "find" iterates over the array and returns the iterator when element found.)
    vector<int>::iterator it = find(arr.begin(), arr.end(), key);

    if(it!=arr.end()){
        cout<<"Element found at index : "<< it - arr.begin()<<endl;
    }
    else{
        cout<<"Element not found."
    }
}