#include <iostream>
#include <vector>
using namespace std;

int main() {
	// Vector demo

	// vector<int> arr = {1,2, 3, 4, 5, 6};

	//Fill Constructor
	vector<int> arr(10, 7);
	//push_back O(1) time; O(n) is once in every N iterations, so it averages out to O(1).
	arr.push_back(16);

	//Displaying elements
	for(int i = 0; i< arr.size(); i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	//size of the vector(Number of elements)
	// cout<<arr.size()<<endl;

	// //capacity of the vector(Actual memory allocated to this vector/sizeof specified datatype)
	// cout<<arr.capacity()<<endl;

	return 0;
}

