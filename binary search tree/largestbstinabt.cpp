#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class NodeValue {
public:
    int maxNode, minNode, sum;
    bool isBST;
    NodeValue(int minNode, int maxNode, int sum, bool isBST) 
        : minNode(minNode), maxNode(maxNode), sum(sum), isBST(isBST) {}
};

class Solution {
private:
    int maxSum = 0;

    NodeValue maxSumBSTHelper(TreeNode* root) {
        // An empty tree is a BST of sum 0.
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0, true);
        }

        // Get values from left and right subtree of current tree.
        auto left = maxSumBSTHelper(root->left);
        auto right = maxSumBSTHelper(root->right);

        // Check if the current tree is a BST.
        if (left.isBST && right.isBST && left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST.
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), currSum, true);
        }

        // Otherwise, return a value indicating this subtree is not a BST.
        return NodeValue(INT_MIN, INT_MAX, max(left.sum, right.sum), false);
    }

public:
    int maxSumBST(TreeNode* root) {
        maxSumBSTHelper(root);
        return maxSum;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(6);

    Solution sol;
    cout << "The maximum sum of BST in the binary tree is: " << sol.maxSumBST(root) << endl;

    // Clean up memory
    delete root->right->right->right;
    delete root->right->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
