#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution
{
    public:
    bool isbalanced(Node*root)
    {
        return dfsheight(root)!=-1;
    }

    int dfsheight(Node*root)
    {
        if(root==nullptr){
        return 0;
        }
        int lh=dfsheight(root->left);
        int rh=dfsheight(root->right);
        if(lh==-1)
        {
            return -1;
        }
        if(rh==-1)
        {
            return -1;
        }
        if(abs(lh-rh)>1)
        {
            return -1;
        }
        return max(lh,rh)+1;
    }
};
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Creating an instance of the Solution class
    Solution solution;
    if(solution.isbalanced(root))
    {
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balaced"<<endl;
    }
    return 0;
}