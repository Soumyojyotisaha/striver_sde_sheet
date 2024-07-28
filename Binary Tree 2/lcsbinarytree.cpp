#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
Node* lca(Node*root,Node*p,Node*q)
{
    if(root==nullptr||root==p||root==q){
    return root;
    }
    Node*left=lca(root->left,p,q);
    Node*right=lca(root->right,p,q);
    if(left == NULL) {
        return right;
        }
        else if(right == NULL) {
        return left;
        }
        else { //both left and right are not null, we found our result
         return root;
        }
    }
};
int main()
{
Solution sol;

    // Constructing the binary tree
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Node* p = root->left;  // Node with value 5
    Node* q = root->right; // Node with value 1

    Node* result = sol.lca(root, p, q);

    cout << "Result: " << result->data << endl;
}
