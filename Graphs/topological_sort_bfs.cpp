//topological sorting is basically sorting the tasks based on their indegrees i.e. in a way that there are no dependencies left for any task.
//only applicable for Directed Acyclic Graphs.

/*
    Algorithm:
    1. calculate indegree for every node
    2. topological sort using bfs
*/

#include<iostream>
#include<map>
#include<cstring>
#include<queue>
#include<list>
using namespace std;

class Graph{

    list<int> *l;
    int V;

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        //directed acyclic graph
        l[x].push_back(y);
    }

    //topological sort
    void topological_sort(){
        vector<int> indegree(V, 0);     //assuming that every node has an indegree 0 in the beginning

        //iterating over all the edges to find the correct indegree
        for(int i = 0; i<V; i++){
            for(auto nbr : l[i]){
                indegree[nbr]++;            //if in the adj list, x->(y1, y2) then indegrees of y1 and y2 should be incremented by 1.
            }
        }

        //bfs
        queue<int> q;
        //initialise the q with nodes having 0 indegree
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        //start popping
        while(!q.empty()){
            int node =  q.front();
            cout<<node<<" ";
            q.pop();

            //iterate  over the neighbours of this node and reduce their indegree by 1;
            for(auto nbr : l[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    //ready for processing
                    q.push(nbr);
                }
            }
        }
    }
};

int main(){
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(4,5);
    g.addEdge(1,4);
    g.addEdge(1,2);
    
    g.topological_sort();
}