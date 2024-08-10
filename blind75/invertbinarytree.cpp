#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        // Swap the left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively invert the children
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// Function to print the tree in level-order
void printLevelOrder(TreeNode* root) {
    if (!root) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if (node->left) {
            q.push(node->left);
        }

        if (node->right) {
            q.push(node->right);
        }
    }
    cout << endl;
}

// Function to delete the tree and avoid memory leaks
void deleteTree(TreeNode* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Original tree level-order: ";
    printLevelOrder(root);

    // Invert the binary tree
    root = solution.invertTree(root);

    cout << "Inverted tree level-order: ";
    printLevelOrder(root);

    // Clean up memory
    deleteTree(root);

    return 0;
}
