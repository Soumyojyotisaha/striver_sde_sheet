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
    Node* populate(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node* curr = root;
        while (curr->left != nullptr) {
            Node* temp = curr;
            while (curr != nullptr) {
                curr->left->next = curr->right;
                curr->right->next = (curr->next == nullptr) ? nullptr : curr->next->left;
                curr = curr->next;
            }
            curr = temp->left;
        }
        return root;
    }
};

void printNextPointers(Node* root) {
    if (root == nullptr) {
        return;
    }
    Node* levelStart = root;
    while (levelStart != nullptr) {
        Node* curr = levelStart;
        while (curr != nullptr) {
            cout << curr->data << " -> ";
            if (curr->next) {
                cout << curr->next->data << " ";
            } else {
                cout << "nullptr ";
            }
            curr = curr->next;
        }
        cout << endl;
        levelStart = levelStart->left;
    }
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
    sol.populate(root);

    printNextPointers(root);

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
