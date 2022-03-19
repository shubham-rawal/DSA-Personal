/*
    Given a binary search tree, you need to return true if the tree is symmetric or false if it's not. ( symmetric tree is when the tree is the mirror image about the root node ).
*/

#include<iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

bool symmetric(Node* root1, Node* root2){
    //base case
    if(root1 and root2 == NULL) return true;

    if(root1 and root2 and root1->key == root2->key){
        return symmetric(root1->left, root2->right) and symmetric(root1->right, root2->left);
    }
    return false;
}

bool isSymmetric(Node* root){
    return symmetric(root, root);
}

int main(){
    
}