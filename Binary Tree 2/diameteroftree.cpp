#include <bits/stdc++.h>
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
    int diameter=0;
    int height(Node*root)
    {
        if (root==nullptr){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);
    }
    int diameterbt(Node*root)
    {
        height(root);
        return diameter;
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

    // Creating an instance of the Solution class
    Solution solution;

    // Calculate the diameter of the binary tree
    int diameter = solution.diameterbt(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}
