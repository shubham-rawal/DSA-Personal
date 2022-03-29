#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    Node* left;
    Node* right;
    
    Node(int key){
        this->key = key;
        left = right = NULL;
    }
};

Node* insert(Node*root, int key){
    //base case
    if(root == NULL)    return new Node(key);

    //rec case
    if(key < root->key){
        root->left = insert(root->left, key);
    }
    else{
        root->right = insert(root->right, key);
    }

    return root;
}

void printInOrder(Node* root){
    //base case
    if(root==NULL)  return;

    //rec case
    printInOrder(root->left);
    cout<<root->key<<" ";
    printInOrder(root->right);
}


Node* findMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

//Time Complexity : O(H) ---> worst case is O(N) for a skewed tree, best case is O(logN);
bool search(Node* root, int key){
    //base case
    if(root==NULL)  return false;
    if(key == root->key)    return true;

    //rec case
    if(key < root->key){
        return search(root->left, key);
    }
    return search(root->right, key);
}


//Deletion
Node* remove(Node* root, int key){
    //base case
    if(root == NULL)    return NULL;

    else if(key < root->key){
        root->left = remove(root->left, key);
    }
    else if(key > root->key){
        root->right = remove(root->right, key);
    }
    else{
        //when the current node matches with the key, we perform this
        //no children
        if(root->left == NULL and root->right == NULL){
            delete root;
            root = NULL;
        }
        //single child
        else if(root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }

        //two children
        else{
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
    }
    return root;
}

//Print Range -- Print all elements in the BST that lies between k1 and k2
void printRange(Node* root, int k1, int k2){
    if(root == NULL)    return;

    if(root->key >= k1 and root->key <= k2){
        //call on both sides
        printRange(root->left, k1, k2);
        cout<<root->key<<" ";
        printRange(root->right, k1, k2);
    }
    else if(root->key > k2){
        printRange(root->left, k1, k2);
    }
    else{
        //root->key < k1
        printRange(root->right, k1, k2);
    }
}


int main(){

    Node* root = NULL;

    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int n = sizeof(arr)/sizeof(int);

    for(int i = 0; i < n; i++){
        root = insert(root, arr[i]);
    }

    // int key;
    // cin>>key;
    // root = remove(root, key);
    // printInOrder(root);
    // cout<<endl;
    // cout<<search(root, 4);

    printRange(root, 5, 12);


    return 0;
}
