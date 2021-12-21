#include <iostream>
#include <vector>
using namespace std;

int main() {
	//2d Vector i.e. vector of vector

	//unlike a 2d array, each row of a 2d vector can have different number of elements
	vector<vector<int>> arr = {
		{1, 2, 3},				//<------ The whole arr[i] is a vector
		{4, 5, 6},
		{7, 8, 9, 10}, 
		{11, 12}
	};

	arr[0][0]+=10;		//access specific element

	//Iteration
	for(int i = 0; i< arr.size(); i++){
		for(int number : arr[i])
			cout<<number<<" ";

		cout<<endl;
	}


	return 0;
}

