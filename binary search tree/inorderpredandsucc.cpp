#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right; 
    
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        pre = inorderPredecessor(root, key);
        suc = inorderSuccessor(root, key);
    }

private:
    Node* inorderSuccessor(Node* root, int key) {
        Node* successor = nullptr;
        while (root != nullptr) {
            if (key >= root->key) {
                root = root->right;
            } else {
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }

    Node* inorderPredecessor(Node* root, int key) {
        Node* predecessor = nullptr;
        while (root != nullptr) {
            if (key <= root->key) {
                root = root->left;
            } else {
                predecessor = root;
                root = root->right;
            }
        }
        return predecessor;
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
    Node* p = root->right; // Node with value 12

    Node* pre = nullptr;
    Node* suc = nullptr;
    sol.findPreSuc(root, pre, suc, p->key);
    
    if (pre) {
        cout << "Inorder Predecessor of " << p->key << " is " << pre->key << endl;
    } else {
        cout << "Inorder Predecessor not found" << endl;
    }

    if (suc) {
        cout << "Inorder Successor of " << p->key << " is " << suc->key << endl;
    } else {
        cout << "Inorder Successor not found" << endl;
    }

    // Clean up memory
    cleanUpMemory(root);

    return 0;
}
