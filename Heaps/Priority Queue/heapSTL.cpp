#include<iostream>
#include<queue>
using namespace std;

int main(){
    int arr[] = {10, 15, 20, 13, 6, 90};
    int n = sizeof(arr)/sizeof(int);

    priority_queue<int> heap;

    for(int i = 0; i<n; i++){
        heap.push(arr[i]);
    }

    while(!heap.empty()){
        cout<<heap.top()<<endl;
        heap.pop();
    }
    
    return 0;
}