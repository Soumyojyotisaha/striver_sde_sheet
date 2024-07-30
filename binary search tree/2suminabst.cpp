#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        
        int i = 0, j = inorder.size() - 1;
        
        while (i < j) {
            int sum = inorder[i] + inorder[j];
            if (sum == k) {
                return true;
            } else if (sum < k) {
                i++;
            } else {
                j--;
            }
        }
        
        return false;
    }

    // Function to perform inorder traversal and store the result in a vector
void inorderTraversal(TreeNode* root, vector<int>& inorder) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
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
    int k=20;
    bool result=sol.findTarget(root,k);
    if(result)
    {
        cout<<"found"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
    return 0;
}