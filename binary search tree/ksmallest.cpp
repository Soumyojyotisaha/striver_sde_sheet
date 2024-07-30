#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* node, int& counter, int& ksmallest, int k) {
        if (node == nullptr || counter >= k) {
            return;
        }
        inorder(node->left, counter, ksmallest, k);
        counter++;
        if (counter == k) {
            ksmallest = node->val;
            return;
        }
        inorder(node->right, counter, ksmallest, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ksmallest = INT_MIN;
        int counter = 0;
        inorder(root, counter, ksmallest, k);
        return ksmallest;
    }
};

// Helper function to insert a new node in BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

int main() {
    TreeNode* root = nullptr;
    vector<int> keys = {50, 30, 20, 40, 70, 60, 80};
    for (int key : keys) {
        root = insert(root, key);
    }

    Solution solution;
    int k = 3;
    int kth_smallest = solution.kthSmallest(root, k);
    cout << "The " << k << "rd smallest element is " << kth_smallest << endl;

    return 0;
}
