#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};
class Solution
{
    public:
    vector<vector<int>>levelorder(TreeNode*root)
    {
        vector<vector<int>>ans;
        if(root==nullptr)
        {
            return ans;

        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            int size=q.size();
        for(int i=0;i<size;i++)
        {
         TreeNode* node=q.front();
         q.pop();
        level.push_back(node->data);
        if(node->left!=nullptr)
        {
            q.push(node->left);
        }
        if(node->right!=nullptr)
        {
            q.push(node->right);
        }
        }
        ans.push_back(level);
        }
        return ans;
    }
};
void print(const vector<int>&vec)
{
    for(int num:vec)
    {
        cout<<num<<" ";
    }
    cout<<endl;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<vector<int>>result=solution.levelorder(root);
    cout<<"level order traversal"<<endl;
    for(const vector<int>& level:result ){
    print(level);
    }
    return 0;
}