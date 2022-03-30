 #include<vector>
 using namespace std;

//Min/Max Heap
 class Heap{
    vector<int> v;
    bool isMin;

    //heapify
    void heapify(int i){
        
        int left = 2*i;
        int right = 2*i + 1;

        //assumption
        int minIdx = i;
        //first we check if the left node exists, and if it is smaller than the root node
        if(left < v.size() and compare(v[left], v[minIdx])){
            minIdx = left;
        }
        //now we check if the right node exists, and if it is smaller than the min of root&left nodes.
        if(right < v.size() and compare(v[right], v[minIdx])){
            minIdx = right;
        }

        //if minIdx has changed
        if(minIdx != i){
            swap(v[i], v[minIdx]);
            heapify(minIdx);
        }

    }

    bool compare(int a, int b){
        if(isMin == true){
            return a<b;
        }
        return a>b;
    }


public:
    Heap(int size = 10, bool isMin = true){
        v.reserve(size + 1);
        v.push_back(-1);
        this->isMin = isMin;
    }

    //push
    void push(int data){
        //add data to the end of the heap
        v.push_back(data);

        //heapify up
        int idx = v.size() - 1;
        int parent = idx/2;
        while(idx > 1 and compare(v[idx], v[parent])){
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent/2;
        }
    }

    //return min/max element
    int top(){
        return v[1];
    }

    //remove the min element
    void pop(){
        //1. Swap the first and last elements since we cannot delete the root node but we can delete the leaf node.
        swap(v[1], v[v.size() - 1]);
        //2. Remove the last element
        v.pop_back();
        //3. Heapify method on the 1st node.
        heapify(1);
    }

    //isEmpty
    bool empty(){
        return v.size() == 1;
    }
 };