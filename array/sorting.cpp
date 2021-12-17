#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//Bubble Sort Algorithm
void bubbleSort(int arr[], int n){
    //TIME COMPLEXITY : O(N^2)
    /*
        We need to do n-1 iterations and in each iteration we compare each element to its next element (from index 0 to n-1-times) and if a[j]>a[j+1], we swap a[j] and a[j+1].
    */
        for(int times = 1 ; times < n ; times++){               //If we sort n - 1 elements of an array of n elements, the 1st element is automatically sorted, hence the number of iterations of each process is n - 1 and only 1 element is being sorted in each process.
            for(int j = 0 ; j <= n - 1 - times; j++){          //Since all sorted elements are placed at the end, we are sure that the end elements after each iteration are already sorted, so we need not run the loop till then.
                if(arr[j]>arr[j+1])
                    swap(arr[j], arr[j+1]);
            }
        }
   }

//Insertion Sort Algorithm
void insertionSort(int arr[], int n){
    //TIME COMPLEXITY : O(n^2), best case should be O(n).
    /*
        Compare this to holding a few unsorted cards in your hand. 
        Suppose their order is 5, 7, 8, 9 and we want to insert 6.
        We will CREATE A SPACE BETWEEN 5 & 7 and INSERT 6 IN THAT SPACE. This is exactly what we do in insertion sort.
    */
   for(int i = 1; i<n; i++){
       int current = arr[i];
       int prev = i - 1;
       
       //loop to find the right index where the element current should be inserted
       while(prev >= 0 && arr[prev]>current){
           arr[prev+1] = arr[prev];
           prev = prev - 1;
       }
       arr[prev+1] = current;
   }
}

//Selection Sort Algorithm
void selectionSort(int arr[], int n){
    //TIME COMPLEXITY : O(n^2)
    /*
        Idea is to repeatedly find the minimum element in the unsorted array and place it in the beginning.
    */
   for(int pos = 0; pos <= n-2; pos++){
       int minIndex = pos;
       for(int i = pos; i<n; i++)
       {
           if(arr[i]<arr[minIndex])
           {
               minIndex = i;
           }
       }
       //Swap outside the loop to prevent unnecessary multiple swapping
       swap(arr[pos], arr[minIndex]);
   }
}

//Counting Sort Algorithm
void countingSort(int arr[], int n){
    //TIME COMPLEXITY : O(N + Range)
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


//NOTE: C++ provides us with an inbuilt sorting function called as sort(). It is quickSort with TIME COMPLEXITY AS O(NlogN) present in the header file #include<algorithm>. We need to provide the start index and end index as sort(arr, arr + n) to sort from [start, end).
//In some cases, countingSort may be more efficient.

//Comparator function
int compare(int a, int b){
    cout<<"Comparing "<<a<<" and "<<b<<endl;
    return a>b;
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