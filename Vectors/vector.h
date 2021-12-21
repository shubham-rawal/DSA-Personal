//Defining a template so as to tell the compiler that this is a generic class of datatype which will be defined later.

template<typename T>
//Creating a Vector class so that we can create and use it's objects.
class Vector{
	//DataMembers

	//Since it is a dynamic memory, we have to have a pointer.
	T *arr;

	//Stores the current size of the vector.
	int cs;

	//Stores the maximum size of the vector(capacity).
	int ms;

public:
	Vector(int max_size = 1){
		cs = 0;
		ms = max_size;
		arr = new T[ms];
	}

	//Push Back
	void push_back(const  T d){
		//Two cases

		if(cs==ms){
			//create a new array with double capacity, copy elements and delete old one
			T *oldArray = arr;
			ms = 2*ms;
			arr = new T[ms];

			//copy the elements
			for(int i = 0; i<cs; i++){
				arr[i] = oldArray[i];
			}

			//delete oldArray
			delete [] oldArray;
		}
		arr[cs++] = d;
	}

	//Pop Back
	void pop_back(){
		if(cs>=0)
			cs--;
	}


		// const functions are those that do not/ cannot modify the data members of the class.
	//isEmpty
	bool isEmpty() const{
		return cs==0;
	}

	//front
	T front() const{
		return arr[0];
	}

	//back
	T back() const{
		return arr[cs-1];
	}

	//at
	T at(int i) const{
		return arr[i];
	}

	//size
	int size() const{
		return cs;
	}

	//capacity
	int capacity() const{
		return ms;
	}

	//operator overload
	T operator[](const int i){
		return arr[i];
	}

};