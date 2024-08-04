#include <iostream>
#include <vector>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform inorder traversal
// of the tree and store values in 'arr'
void inorder(Node* root, vector<int> &arr){
    if(root == nullptr) {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// Function to initiate inorder traversal
// and return the resulting vector
vector<int> inOrder(Node* root){
    vector<int> arr;
    inorder(root, arr);
    return arr;
}

// Function to perform preorder traversal
// of the tree and store values in 'arr'
void preorder(Node* root, vector<int> &arr){
    if(root == nullptr) {
        return;
    }
    arr.push_back(root->data);
    preorder(root->left, arr);
    preorder(root->right, arr);
}

// Function to initiate preorder traversal
// and return the resulting vector
vector<int> preOrder(Node* root){
    vector<int> arr;
    preorder(root, arr);
    return arr;
}

// Function to perform postorder traversal
// of the tree and store values in 'arr'
void postorder(Node* root, vector<int> &arr){
    if(root == nullptr) {
        return;
    }
    postorder(root->left, arr);
    postorder(root->right, arr);
    arr.push_back(root->data);
}

// Function to initiate postorder traversal
// and return the resulting vector
vector<int> postOrder(Node* root){
    vector<int> arr;
    postorder(root, arr);
    return arr;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting inorder traversal
    vector<int> inOrderResult = inOrder(root);
    // Getting preorder traversal
    vector<int> preOrderResult = preOrder(root);
    // Getting postorder traversal
    vector<int> postOrderResult = postOrder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    for(int val : inOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    for(int val : preOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    // Displaying the postorder traversal result
    cout << "Postorder Traversal: ";
    for(int val : postOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
