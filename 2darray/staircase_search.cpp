//O(N + M)

//Given a 2d array sorted row and column wise, search for an element.
//Note : take the (0, M-1)th  or  the (N-1, 0)th element.

#include<iostream>
#include <utility>
using namespace std;

pair<int, int> staircaseSearch(int arr[][4], int n, int m, int key){
    int row_idx = 0;
    int col_idx = m-1;

    pair<int, int> null;
    null.first = -1;
    null.second = -1;

    while(row_idx <= n-1 and col_idx >= 0){
        if(arr[row_idx][col_idx] == key){
            pair<int, int> ans;
            ans.first = row_idx;
            ans.second = col_idx;
            return ans;
        }
        else if(arr[row_idx][col_idx] > key){
            col_idx--;
        }
        else
            row_idx++;
    }
    return null;
}
int main(){

    int arr[][4] = {
                    {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                    };

    int n = 4, m = 4, key = 33;

    pair<int, int> location = staircaseSearch(arr, n, m, key);
    if(location.first == -1){
        cout<<"Element not found"<<endl;
    }
    else
        cout<<"Element found at "<<location.first<<" , "<<location.second<<endl;
}