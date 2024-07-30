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
    int ceilinbst(TreeNode* root, int key) 
    {
        int ceil = -1;
        while (root) {
            if (root->data == key) {
                ceil= root->data;
                return ceil;
            }
            if (key > root->data) {
                root = root->right;
            } else {
                ceil = root->data;
                root = root->left;
            }
        }
        return ceil;
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
    int key = 5;
    cout << "Ceil of " << key << " in BST is " << sol.ceilinbst(root, key) << endl;
    return 0;
}

