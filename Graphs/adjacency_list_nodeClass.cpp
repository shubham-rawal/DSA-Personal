#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;

//In this case each node is not necessarily an integer but it's an object of the Node class.

class Node{
public:
    string name;
    list<string> nbrs;      //we will store the list of neighbours of the particular node here itself, so as to minimalise the usage of adjacency list.

    Node(string name){
        this->name = name;
    }
};

class Graph{
    //All Nodes should be accessible using their names.
    //so we create a Hashmap(cityName, Node*)

    unordered_map<string, Node*> m;


public:
    Graph(vector<string> cities){
        //the graph constructor will accept the city names as an input as the nodes are to be accessed using the city names.
        for(auto city:cities){
            m[city] = new Node(city);       //we create a node for each city and store it accordingly in the hashmap using the cityName as the key.
        }
    }

    void addEdge(string x, string y, bool undir = false){
        m[x]->nbrs.push_back(y);            //since m[x] gives a Node* value which is a pointer, hence we can access it's other     properties using the -> notation instead of the . notation used for objects.

        if(undir){
            m[y]->nbrs.push_back(x);
        }

    }

    void printAdjList(){
        for(auto cityPair: m){
            auto city = cityPair.first;
            Node *node = cityPair.second;

            cout<<city<<"->";
            for(auto nbr: node->nbrs){
                cout<<nbr<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    vector<string> cities = {"Delhi", "London", "Paris", "New York"};
    Graph g(cities);
    g.addEdge("Delhi", "London");
    g.addEdge("New York", "London");
    g.addEdge("Delhi", "Paris");
    g.addEdge("Paris", "New York");


    g.printAdjList();

    return 0;
}