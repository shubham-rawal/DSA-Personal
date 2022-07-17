//we visit each node, and then call a recursive function to visit all subsequent nodes.
/*
    Algorithm: RECURSIVE

    Time Complexity : O(V+E)
    
*/
#include<iostream>
#include<list>
#include<queue>
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


//--------------------------------------------------------------------------------------->
    //DFS

    void dfsHelper(int node, bool *visited){
        visited[node] = true;
        cout<<node<<", ";

        //make a dfs call to all its unvisited neighbours
        for(int nbr: l[node]){          //for the source node, this for loop will run only once. for eg, if 1->(0, 2); then upon calling 0, it automatically will call 2 at some point. Thus it won't call 2 again from this loop.
            if(!visited[nbr]){
                dfsHelper(nbr, visited);
            }
        }
        return;
    }

    void dfs(int source){
        bool *visited = new bool[V]{0};         //since we can create this visited array only once, we have to use a helper function
        dfsHelper(source, visited);

    }
//<---------------------------------------------------------------------------------------

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
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    // g.printAdjList();
    g.dfs(1);

    return 0;

}