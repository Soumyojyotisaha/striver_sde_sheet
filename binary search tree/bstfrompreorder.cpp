#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right; 
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Node* bst(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

private:
    Node* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound)
            return nullptr;
        Node* root = new Node(A[i++]);
        root->left = build(A, i, root->data);
        root->right = build(A, i, bound);
        return root;
    }
};

void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};  // Example input
    Solution solution;
    Node* root = solution.bst(preorder);

    cout << "Inorder traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
