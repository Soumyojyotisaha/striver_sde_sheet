#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* searchbst(TreeNode* root, int val) {
        while (root != nullptr && root->data != val) {
            root = val < root->data ? root->left : root->right;
        }
        return root;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    Solution sol;
    int val = 10;
    TreeNode* result = sol.searchbst(root, val);
    
    if (result) {
        cout << "Found node with value: " << result->data << endl;
    } else {
        cout << "Value not found in BST" << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
