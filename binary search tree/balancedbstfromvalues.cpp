#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* next;
    Node(int val) : data(val), left(nullptr), right(nullptr), next(nullptr) {}
};
class Solution
{
public:
Node* constructbst(const vector<int>&nums,int left,int right)
{
    if(left>right)
    {
        return nullptr;
    }
    int mid=left+(right-left)/2;
    Node* node=new Node(nums[mid]);
    node->left=constructbst(nums,left,mid-1);
    node->left=constructbst(nums,mid+1,right);
    return node;
}
Node* sortedArray(vector<int>&nums)
{
    return constructbst(nums,0,nums.size()-1);
}
};
void print(Node*root)
{
  if(root==nullptr)
  {
    return;

  } 
  print(root->left);
  cout<<root->data<<" ";
  print(root->right); 
}

int main()
{
    Solution sol;
   vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Node* root = sol.sortedArray(nums);
    cout<<"Inorder traversal:"<<" ";
    print(root);
    cout<<endl;

    delete root;
    return 0;
}