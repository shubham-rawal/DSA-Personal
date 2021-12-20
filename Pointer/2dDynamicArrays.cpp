/*
    There is no direct way to create 2d arrays dynamically. So, what we can do is create multiple 1d Arrays, and store the addresses (of the the first element) of these 1d arrays in another dynamically created array (called the ARRAY OF POINTERS). (Why dynamically? because that way it will act as a proper 2d array).
    Next we can create a pointer that points towards this 1d arrayOfPointers that stores the addresses of the multiple 1d arrayS. (refer code for more clarity)/
*/
#include<iostream>

using namespace std;

int** create2DArray(int rows,int cols){

    //initialisation of the 2d array.
    int ** arr = new int* [rows];

    for(int i = 0; i<rows; i++){
        arr[i] = new int [cols];
    }

    //putting in the data
    int value = 0;
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            arr[i][j] = value++;
        }
    }

    return arr;
}

//Since this is a dynamically created array, it does not get freed up automatically after the function call has ended. Thus we can directly use another pointer to point towards this memory (the array of pointers ) from the main function. This would not have been possible in case of static 2d Array.
int main(){
    int rows, cols;
    cin>>rows>>cols;

    int ** arr = create2DArray(rows, cols);

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


//deleting/freeing up the memory.
    for(int i = 0; i<rows; i++)
    {
        delete [] arr[i];
        cout<<i<<" Row deleted"<<endl;
    }
    delete [] arr;
    cout<<"array of pointers deleted"<<endl;

    return 0;
}