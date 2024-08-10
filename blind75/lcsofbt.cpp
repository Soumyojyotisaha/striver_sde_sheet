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
        if (!root) {
            return nullptr;
        }

        // If root is either p or q, return root
        if (root == p || root == q) {
            return root;
        }

        // Recur on left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right calls returned non-null, root is LCA
        if (left && right) {
            return root;
        }

        // Otherwise, return the non-null child (if any)
        return left ? left : right;
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

// Function to create a binary tree for testing
TreeNode* createTestTree() {
    // Create a binary tree:
    //       3
    //      / \
    //     5   1
    //    / \ / \
    //   6  2 0  8
    //     / \
    //    7   4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    return root;
}

int main() {
    Solution solution;

    // Create a binary tree for testing
    TreeNode* root = createTestTree();

    // Nodes to find LCA
    TreeNode* p = root->left;      // Node with value 5
    TreeNode* q = root->left->right->right; // Node with value 4

    // Find the lowest common ancestor
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    if (lca) {
        cout << "The lowest common ancestor of nodes " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "The lowest common ancestor does not exist." << endl;
    }

    // Clean up memory
    deleteTree(root);

    return 0;
}
