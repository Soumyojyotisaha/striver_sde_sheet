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
    int floorinbst(TreeNode* root, int key) {
        int floor = -1;
        while (root) {
            if (root->data == key) {
                floor = root->data;
                return floor;
            }
            if (key > root->data) {
                floor = root->data;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return floor;
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
    cout << "Floor of " << key << " in BST is " << sol.floorinbst(root, key) << endl;
    return 0;
}
