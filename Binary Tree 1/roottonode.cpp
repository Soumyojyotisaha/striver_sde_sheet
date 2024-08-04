#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};
class Solution
{
public:
bool getpath(Node* root, vector<int>& arr, int x)
{
if(!root)
{
    return false;
}
arr.push_back(root->data);
if(root->data==x){
return true;
}
if(getpath(root->left,arr,x)||getpath(root->right,arr,x))
{
    return true;
}
arr.pop_back();
return false;
}
vector<int> solve(Node*A,int B)
{
    vector<int> ans;
    if(A==nullptr)
    {
        return ans;
    }
    getpath(A,ans,B);
    return ans;
}
};

int main()
{
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Solution sol;
    int target=7;
    vector<int>path=sol.solve(root,target);
    cout << "Path from root to leaf with value:" <<target << ": ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }

    return 0;
}