#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inmap;
        for (int i = 0; i < inorder.size(); ++i) {
            inmap[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, map<int, int>& inmap) {
        if (prestart > preend || instart > inend) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = inmap[root->data];
        int numsleft = inroot - instart;

        root->left = buildTree(preorder, prestart + 1, prestart + numsleft, inorder, instart, inroot - 1, inmap);
        root->right = buildTree(preorder, prestart + numsleft + 1, preend, inorder, inroot + 1, inend, inmap);

        return root;
    }
};

// Function to print the inorder traversal of a tree
void printInorder(TreeNode* root) {
    if (!root) {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Function to print the given vector
void printVector(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    cout << "Inorder Vector: ";
    printVector(inorder);

    cout << "Preorder Vector: ";
    printVector(preorder);

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder of Unique Binary Tree Created: " << endl;
    printInorder(root);
    cout << endl;

    return 0;
}
