#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* next;
    Node(int val) : data(val), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    Node* lca(Node* root, Node* p, Node* q) {
        if (root == nullptr) {
            return nullptr;
        }
        int curr = root->data;
        if (curr < p->data && curr < q->data) {
            return lca(root->right, p, q);
        }
        if (curr > p->data && curr > q->data) {
            return lca(root->left, p, q);
        }
        return root;
    }
};

void cleanUpMemory(Node* root) {
    if (root == nullptr) {
        return;
    }
    cleanUpMemory(root->left);
    cleanUpMemory(root->right);
    delete root;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    Solution sol;

    Node* p = root->left;  // Node with value 4
    Node* q = root->right; // Node with value 12

    Node* ancestor = sol.lca(root, p, q);
    if (ancestor) {
        cout << "LCA of " << p->data << " and " << q->data << " is " << ancestor->data << endl;
    } else {
        cout << "LCA not found" << endl;
    }

    // Clean up memory
    cleanUpMemory(root);

    return 0;
}

