#include<vector>
#include<iostream>
using namespace std;

template<typename T>
class Stack{
    vector<T> arr;
public:
    // Stack();         <--- this is not working for some reason

    //push
    void push(T data){
        arr.push_back(data);
    }

    //pop
    void pop(){
        arr.pop_back();
    }

    //empty
    bool empty(){
        return arr.size() == 0;
    }

    //top
    T top(){
        return arr[arr.size() - 1];
    }
};