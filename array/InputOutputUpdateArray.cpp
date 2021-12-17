#include<iostream>
using namespace std;

int main(){
    //Creating an array and statically allocating a memory of 4*100 bytes (since 1 integer is of 4 bytes)
    int marks[100] = {-1};
    
    //since this array has not been initialised, it currently contains some random garbage values.

    int n;
    cout<<"Enter the number of students : ";
    cin>>n;
    
    //Input array elements from the user.
    for(int i = 1; i<=n; i++)
        cin>>marks[i];

    //Output elements from a pre-existing array
    cout<<"Displaying the marks of students : "<<endl;
    for(int i = 1; i<=n; i++){
        cout<<marks[i]<<", ";
    }
    cout<<endl;

   //Update values of the elements of the array
   cout<<"Updating the marks of students : "<<endl;
   for(int j=1;j<100;j++){
       marks[j]*=2;
       cout<<marks[j]<<", ";
       //this would multiply the marks of each element of the array by 2.
   }
   cout<<endl;

    return 0;
}