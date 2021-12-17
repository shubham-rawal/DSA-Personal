// WAF that takes an n x m 2d Array, prints all elements in a spiral order, starting from top left goes to right.

/*

    1 2 3 4 
    5 6 7 8 
    9 10 11 12
    13 14 15 16 

    output should be : 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10


How : In each iteration, we will cover the boundary of the matrix, and after each iteration, we will move inwards.

We can take 4 variables to store indexes : startColumn, endColumn, startRow & endRow.

In each iteration we print : 
1. startRow(startColumn...endColumn)
2. endColumn(startRow+1...endRow)
3. endRow(endColumn-1...startColumn)     <===== backward
4. startColumn(endRow-1...startRow+1)    <===== backward


After each iteration i.e for the outer loop, we do : startRow++, endColumn--, endRow--, startColumn++

*/

#include<iostream>

using namespace std;


void spiralPrint(int arr[][4], int n, int m){
    
    //4 variables 
    int startRow = 0, endRow = n-1, endColumn = m-1, startColumn = 0;

    //OuterLoop (Traverse Outer Boundary using 4 inner loops)
    //Careful while putting condition of outer loop as it may never print a column or print it twice (once while top -> bottom & once while bottom -> top).
    while(startColumn <= endColumn and startRow <= endRow ){
        
        //Start Row
        for(int col = startColumn; col <= endColumn; col++){
            cout<<arr[startRow][col]<<" ";
        }

        //End Column 
        for(int row = startRow + 1 ; row <= endRow; row++){
            cout<<arr[row][endColumn]<<" ";
        }

        //End Row
        for(int col = endColumn - 1 ; col >= startColumn ; col--){

            //Avoid duplicate printing of columns
            if(startColumn == endColumn){
                break;
            }
            cout<<arr[endRow][col]<<" ";
        }

        //Start Column
        for(int row = endRow - 1 ; row >= startRow + 1; row--){
            if(startRow == endRow){
                break;
            }
            cout<<arr[row][startColumn]<<" ";
        }

        startColumn++;
        endColumn--;
        startRow++;
        endRow--;

    }

}

int main(){
    int arr[][4] = { {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16},};

    int n = 4, m = 4;

    spiralPrint(arr, n, m);

    return 0;
}