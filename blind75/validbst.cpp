#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
    public:
    bool isvalid(TreeNode*root)
    {
        return valid(root,LONG_MIN,LONG_MAX);
    }
    private:
    bool valid(TreeNode*node,long left,long right)
    {
        if(node==nullptr)
        {
          return true;
        }
        if(!(node->val<right && node->val>left))
        {
            return false;
        }
        else
        {
            return valid(node->left,left,node->val) && valid(node->right,node->val,right);
        }
    }
};
int main() {
    // Create nodes and build the tree
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    Solution sol;
    bool result = sol.isvalid(root);
cout << "Is the tree a valid BST? " << (result ? "Yes" : "No") << std::endl;


    return 0;
}