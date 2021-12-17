#include<iostream>
#include<vector>

using namespace std;

//Counting Sort Algorithm
void countingSort(int arr[], int n){
    //TIME COMPLEXITY : O(N + Range) ------> in the worst case after doing all subtractions and everything, the two loops would not run more than N times plus few elements may have the frequency as 0 so (N + Range).
    /*
        CONDITION : Elements can not be negative.
        This is similar to a frequency map. Here, we create another array having elements from 0 to the range of the original array and we store the number of occurences of each element. Then we refill the original array while iterating through the freq array.
    */
   
   //finding the range of the original array.
   int largest = -1;
   for(int i = 0; i < n; i++){
       largest = max(largest, arr[i]);
   }

   //creating a dynamic array/vector of size largest + 1, since we have to include all elements from 0 to largest.;
    vector<int> freq(largest+1, 0);

    //Updating the freq array
    for(int x = 0; x <= largest; x++){
        freq[x]++;
    }

    //Putting back elements from freq to original array based on their number of occurences.
    int j = 0;          //This maintains the position of the original array
    for(int i = 0 ; i<=largest ; i++){
        //This variable i iterates over the frequency array.
        while(freq[i]>0){
            //Treat this like taking out elements from the freq array and placing it into the original array.
            arr[j] = i;                 //Element placed in original array at index j
            j++;                        //Incrementing the index of original array
            freq[i]--;                  //Decrementing the frequency of the element in the current frequency array.
        }
    } 

}

int main(){

 int arr[] = {3, 5, 7, 2, 4, 1, 9, 0};   //the unsorted array.
    int n = sizeof(arr)/sizeof(int);
    cout<<"Unsorted array is : "<<endl;
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //the sort function accepts another function as an optional parameter that is used to define the order of the sorting(ascending or descending).
    countingSort(arr, n);


    cout<<"Sorted array is : "<<endl;
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}