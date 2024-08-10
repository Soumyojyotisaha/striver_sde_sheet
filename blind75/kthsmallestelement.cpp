#include <iostream>
#include <stack>

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* current = root;
        int count = 0;

        while (current || !s.empty()) {
            // Traverse to the leftmost node
            while (current) {
                s.push(current);
                current = current->left;
            }

            // Process the node
            current = s.top();
            s.pop();
            count++;

            // Check if this is the kth smallest element
            if (count == k) {
                return current->val;
            }

            // Move to the right subtree
            current = current->right;
        }

        // If k is out of bounds, return -1 or handle error
        return -1; // or throw an exception
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
    //       3
    //      / \
    //     1   4
    //      \
    //       2
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    return root;
}

int main() {
    Solution solution;

    // Create a binary search tree for testing
    TreeNode* root = createTestTree();

    // Test kth smallest element
    int k = 2;
    int result = solution.kthSmallest(root, k);
    cout << "The " << k << "th smallest element is: " << result << endl;

    // Clean up memory
    deleteTree(root);

    return 0;
}
