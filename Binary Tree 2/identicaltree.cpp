#include <iostream>
#include <algorithm>
#include <climits>

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
    bool isidentical(Node*node1,Node*node2)
    {
        if(node1==nullptr && node2==nullptr)
        {
        return true;
    }
    if(node1==nullptr || node2==nullptr)
    {
        return false;
    }
    return((node1->data==node2->data)&& isidentical(node1->left,node2->left)&&isidentical(node1->right,node2->right));
    }
};
int main() {
    // Node1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    // Node2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);

    Solution solution;
    
    if (solution.isidentical(root1, root2)) {
        cout << "The binary trees are identical." << endl;
    } else {
        cout << "The binary trees are not identical." << endl;
    }

    return 0;
}