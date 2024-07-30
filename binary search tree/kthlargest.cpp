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
    void reverseinorder(Node* node, int& counter, int& klargest, int k) {
        if (node == nullptr || counter >= k) {
            return;
        }
        reverseinorder(node->right, counter, klargest, k);
        counter++;
        if (counter == k) {
            klargest = node->data;
            return;
        }
        reverseinorder(node->left, counter, klargest, k);
    }

    int findkth(Node* root, int k) {
        int klargest = INT_MIN;
        int counter = 0;
        reverseinorder(root, counter, klargest, k);
        return klargest;
    }
};
int main() {
    // Example usage:
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    Solution sol;
    int k=4;
    int result=sol.findkth(root,k);
    cout<<result<<endl;

    return 0;
}
