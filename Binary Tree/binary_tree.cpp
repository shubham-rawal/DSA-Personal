#include<iostream>
#include<queue>
using namespace std;
//We will create a binary tree with the input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

//NOTE : -1 represents NULL

//Anatomy of a Binary Tree Node : each node will consist of three parts :
//1. Data
//2. Address of the left node
//3. Address of the right node

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

//We will build this tree using a recursive function

//PREORDER BUILD OF THE TREE : Root->Left->Right
Node* buildTree(){
    int d;
    cin>>d;

    //base case
    if(d==-1)   return NULL;

    //we keep creating a new node (a sub-root node) towards the left of the existing root node, unless -1 is found.
    //Once the left subtree is complete, we move to the right subtree and follow the same procedure.
    Node* n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

//OUTPUT : 1 2 4 5 7 3 6
void printPreorder(Node* root){
    // base case
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

//OUTPUT : 4 2 7 5 3 6
void printInorder(Node * root){
    // base case
    if(root == NULL)    return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

//OUTPUT : 4 7 5 2 6 3 1
void printPostorder(Node* root){
    // base case
    if(root == NULL)    return;

    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
}


//Level Order Traversal (BREADTH FIRST SEARCH) 
/*
    Expected Output :
    1
    2 3
    4 5 6
    7
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
    Node* root = buildTree();
    // printPreorder(root);
    // cout<<endl;

    // printInorder(root);
    // cout<<endl;

    // printPostorder(root);
    // cout<<endl;

    levelOrderPrint(root);
    cout<<endl;
}