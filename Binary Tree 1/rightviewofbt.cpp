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
    void recursionright(Node* root, int level, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        if (res.size() == level) {
            res.push_back(root->data);
        }
        recursionright(root->right, level + 1, res);
        recursionright(root->left, level + 1, res);
    }
    
    vector<int> rightsideview(Node* root) {
        vector<int> res;
        recursionright(root, 0, res);
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
    vector<int> rightview = sol.rightsideview(root);
    cout << "right view: ";
    for (auto val: rightview) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
