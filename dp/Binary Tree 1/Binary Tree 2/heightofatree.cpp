#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*left;
    Node*right;
Node(int val):data(val),left(nullptr),right(nullptr){}
};
class Solution
{
    public:
    int maxdepth(Node*root)
    {
        if(root==nullptr)
        {
        return 0;
        }
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);
return 1+max(lh,rh);
    }
};
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    

    Solution solution;
    int depth = solution.maxdepth(root);

    cout << "Maximum depth of the binary tree: " << depth << endl;

    return 0;
}
