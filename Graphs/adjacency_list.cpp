#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;        //this is a pointer to an array of lists.

    //since we do not currently know the number of vertices of the graph, we allocate memory dynamically


public:
    Graph(int v){
        V = v;      //number of vertices of the graph
        l = new list<int>[V];           //we create a list of integers and the pointer l points to the 0th element of the list.  
    }

    void addEdge(int i, int j, bool undirected = true){
        l[i].push_back(j);
        if(undirected){
            l[j].push_back(i);
        }
    }

    void printAdjList(){
        //Iterate over all the rows
        for(int i = 0; i<V; i++){
            cout<<i<<"-->";
            //every element of the ith linked list
            for(auto node : l[i]){
                cout<<node<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.printAdjList();

    return 0;

}