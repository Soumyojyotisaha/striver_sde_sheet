#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool issubtree(TreeNode* r, TreeNode* sr) {
        if (!sr) return true;
        if (!r) return false;
        if (sameTree(r, sr)) {
            return true;
        }
        return issubtree(r->left, sr) || issubtree(r->right, sr);
    }

private:
    bool sameTree(TreeNode* r, TreeNode* sr) {
        if (!r && !sr) return true;
        if (r && sr && r->val == sr->val) {
            return sameTree(r->left, sr->left) && sameTree(r->right, sr->right);
        }
        return false;
    }
};
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(0);
    root->left->right->right = new TreeNode(8);

    TreeNode* subtree = new TreeNode(4);
    subtree->left = new TreeNode(1);
    subtree->right = new TreeNode(2);
    subtree->right->left = new TreeNode(0);

    Solution sol;
    bool result = sol.issubtree(root, subtree);

    cout << "Is subtree: " << (result ? "Yes" : "No") << endl;

    return 0;
}