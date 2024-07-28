#include <iostream>
#include <algorithm>
#include <climits>
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
    int maxi=0;
    int maxpathsum(Node* root,int &maxi)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int leftsum=max(0,maxpathsum(root->left,maxi));
        int rightsum=max(0,maxpathsum(root->right,maxi));
        maxi=max(maxi,leftsum+rightsum+root->data);
        return max(leftsum, rightsum) + root->data;
    }

    int maxpath(Node*root)
    {
        int maxi=INT_MIN;
        maxpathsum(root,maxi);
        return maxi;
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

    // Finding and printing the maximum path sum
    int maxPathSum = solution.maxpath(root);
    cout << "Maximum Path Sum: " << maxPathSum << endl;
    return 0;
}