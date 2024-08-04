#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void recursionleft(Node* root, int level, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        if (res.size() == level) {
            res.push_back(root->data);
        }
        recursionleft(root->left, level + 1, res);
        recursionleft(root->right, level + 1, res);
    }
    
    vector<int> leftsideview(Node* root) {
        vector<int> res;
        recursionleft(root, 0, res);
        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution sol;
    vector<int> leftview = sol.leftsideview(root);
    cout << "left view: ";
    for (auto val: leftview) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
