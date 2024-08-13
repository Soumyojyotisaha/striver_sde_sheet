#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Driver code
int main() {
    // Create nodes for tree 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    
    // Create nodes for tree 2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    
    Solution sol;
    bool result = sol.isSameTree(root1, root2);
    
    // Output the result
    std::cout << "Are the two trees the same? " << (result ? "Yes" : "No") << std::endl;
    
    // Cleanup (delete nodes)
    delete root1->left;
    delete root1->right;
    delete root1;
    
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
