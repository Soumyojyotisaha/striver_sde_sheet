#include <iostream>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while (curr) {
            if (p->val > curr->val && q->val > curr->val) {
                curr = curr->right;
            } else if (p->val < curr->val && q->val < curr->val) {
                curr = curr->left;
            } else {
                return curr;
            }
        }

        return nullptr; // In case there is no LCA (shouldn't happen in a valid BST)
    }
};

// Function to delete the tree and avoid memory leaks
void deleteTree(TreeNode* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

// Function to create a binary search tree for testing
TreeNode* createTestTree() {
    // Create a binary search tree:
    //       6
    //      / \
    //     2   8
    //    / \ / \
    //   0  4 7  9
    //     / \
    //    3   5
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    return root;
}

int main() {
    Solution solution;

    // Create a binary search tree for testing
    TreeNode* root = createTestTree();

    // Nodes to find LCA
    TreeNode* p = root->left;  // Node with value 2
    TreeNode* q = root->right; // Node with value 8

    // Find the lowest common ancestor
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    cout << "The lowest common ancestor of nodes " << p->val << " and " << q->val << " is: " << lca->val << endl;

    // Clean up memory
    deleteTree(root);

    return 0;
}
