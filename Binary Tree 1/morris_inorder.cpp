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
    vector<int> inorder(TreeNode* root){
        vector<int> inorder;
        TreeNode* cur=root;
        while(cur!=nullptr)
        {
            if(cur->left==nullptr)
            {
                inorder.push_back(cur->val);
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
                cur=cur->left;
                }
            else
            {
                prev->right=nullptr;
                inorder.push_back(cur->val);
                cur=cur->right;
            }
            }
        }
        return inorder;
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
    vector<int> inorder=sol.inorder(root);
    cout<<"Morris inorder:";
    for(int val:inorder)
    {
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}
