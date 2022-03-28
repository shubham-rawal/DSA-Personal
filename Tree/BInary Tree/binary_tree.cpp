#include<iostream>
#include<queue>
#include<cmath>
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

//Helper function : Height of a tree
int height(Node* root){

    if(root == NULL)    return 0;

    int h1 = height(root->left);

    int h2 = height(root->right);

    return 1 + max(h1, h2);

}

int diameter(Node* root){
    //Time complexity : we're visiting each node and performing the height function at each node which is O(N). Thus the overall complexity of the diameter function becomes O(N^2).
    //refer to the notes for logic.
    //base case
    if(root == NULL)
        return 0;

    //recursive case
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max(D1, max(D2, D3));
}

//Diameter Optimised ------------------------
class HDPair{
public:
    int height;
    int diameter;
};

HDPair optDiameter(Node* root){
    HDPair p;
    //base case
    if(root == NULL){
        p.height = p.diameter = 0;
        return p;
    }

    //otherwise
    HDPair Left = optDiameter(root->left);
    HDPair Right = optDiameter(root->right);

    //for the current node height
    p.height = max(Left.height, Right.height) + 1;

    //for the current node diameter
    int D1 =  Left.height + Right.height;
    int D2 = Left.diameter;
    int D3 = Right.diameter;

    p.diameter = max(D1, max(D2, D3));
    return p;
}

int main(){
    Node* root = buildTree();
    // printPreorder(root);
    // cout<<endl;

    // printInorder(root);
    // cout<<endl;

    // printPostorder(root);
    // cout<<endl;

    // levelOrderPrint(root);
    // cout<<endl;

    cout<<"Diameter of this tree is : "<<diameter(root)<<endl;

    cout<<"Optimised diameter of this tree is : "<<optDiameter(root).diameter<<endl;
}