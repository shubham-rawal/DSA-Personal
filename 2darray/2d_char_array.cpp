#include<iostream>

using namespace std;

int main(){
    char numbers[][10] = {

        //in such implicit declaration, number of rows is optional.
        "one", 
        "two", 
        "three", 
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten", 
        "hundred",
    };

    int nums[][10] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9,
    };



    //printing the entire row
    for(int i = 0; i<6;i++){
        // cout<<nums[i]<<endl;

        cout<<numbers[i]<<endl;
        

        //NOTE: cout treats character arrays differently. That is, when cout<<numbers[i] command is run, it prints the entire string for that index. However same command when used for an integer array gives prints the address of that row since no element has been specified. To output an integer we need to mention the row index and column index, otherwise it just gives us the address of the row index specified. (this is not the case in character 2d arrays. )
    }
}