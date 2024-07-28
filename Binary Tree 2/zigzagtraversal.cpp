#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution
{
    public:
    vector<vector<int>>zigzag(Node*root)
    {
        vector<vector<int>>result;
        if(root==nullptr)
        {
        return result;
        }
        queue<Node*>q;
        q.push(root);
        bool flag=true;
        while(!q.empty())
        {
            int size=q.size();
            vector<int>row(size);
            for(int i=0;i<size;i++)
            {
                Node*node=q.front();
                q.pop();
                int index=flag?i:(size-1-i);
                row[index]=node->data;

                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            flag=!flag;
            result.push_back(row);
        }
        return result;

    }
};

void print(const vector<vector<int>>&result)
{
for(const auto&row:result)
{
    for(int val:row)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}
};
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the zigzag level order traversal
    vector<vector<int>> result = solution.zigzag(root);
    // Print the result
    print(result);

    return 0;
}