#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = right = NULL;
    }
};

Node* levelOrderBuild(){
    int d;
    cin>>d;

    Node* root = new Node(d);

    queue<Node*> q;
    q.push(root);
     

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        int c1, c2;
        cin>>c1>>c2;

        if(c1!=-1){
            curr->left = new Node(c1);
            q.push(curr->left);
        }
        if(c2!=-1){
            curr->right = new Node(c2);
            q.push(curr->right);
        }
    }
    return root;
}

//----------------------------------------------------------
//Level Order Traversal (BREADTH FIRST SEARCH) 


/*
    Expected Output :
    1
    2 3
    4 5 6
    7
       
        
    Since 2, 3 are both children of 1 and once we have reached 2, there is no direct way to reach 3, hence we need to store every node we've visited.
        (i). We need an iterative approach and not a recursive one.
        (ii). We need a data structure to store every node we've visited --> queue(because of it's fifo property).
*/

void levelOrderPrint(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        if(temp == NULL){
            cout<<endl;
            q.pop();
            //insert a new NULL for the next level
            if(!q.empty())  q.push(NULL);
        }
        else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

    return;
}


int main(){
    Node* root = levelOrderBuild();

    levelOrderPrint(root);
    cout<<endl;
}