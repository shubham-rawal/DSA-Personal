//also called level order traversal, we print/visit all the nodes level wise.
/*
    Algorithm:
    we take a source node. we push it into the queue. Then, we mark it as visited and push it's neighbours into the queue. 
    Repeat this process.
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
    //BFS
    void bfs(int source){
        queue<int> q;
        bool *visited = new bool[V]{0};         //again dynamic initialisation as done previously

        q.push(source);
        visited[source] = true; 

        while(!q.empty()){
            //Do some work for every node
            int f = q.front();
            cout<<f<<endl;
            q.pop();

            //Push the neighbours of the current node if they're not already visited.
            for(auto nbr: l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true; 
                }
            }
        }
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
    g.bfs(1);

    return 0;

}