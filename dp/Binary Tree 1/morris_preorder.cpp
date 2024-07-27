#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}

};
class Solution{
    public:
    vector<int> getPreOrderTraversal(TreeNode* root){
        vector<int> preorder;
        TreeNode* cur=root;
        while(cur!=nullptr)
        {
            if(cur->left==nullptr)
            {
                preorder.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                TreeNode*prev=cur->left;
                while(prev->right && prev->right!=cur)
                {
                    prev=prev->right;
                }
                if(prev->right ==nullptr)
                {
                prev->right=cur;
                preorder.push_back(cur->val);
                cur=cur->left;
                }
            else
            {
                prev->right=nullptr;
                
                cur=cur->right;
            }
            }
        }
        return preorder;
    }
    
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    Solution sol;
    vector<int> inorder=sol.getPreOrderTraversal(root);
    cout<<"Morris preorder:";
    for(int val:inorder)
    {
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}
