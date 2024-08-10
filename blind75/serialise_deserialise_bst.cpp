#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <climits>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Serialize the tree to a string
    string serialize(TreeNode* root) {
        vector<string> ans;
        serializeHelper(root, ans);
        return join(ans, ",");
    }
    
    // Deserialize the string back to a tree
    TreeNode* deserialize(const string& data) {
        if (data.empty()) return nullptr;
        vector<int> values = splitToInts(data, ',');
        return deserializeHelper(values, INT_MIN, INT_MAX);
    }

private:
    // Helper function to serialize the tree
    void serializeHelper(TreeNode* node, vector<string>& ans) {
        if (node == nullptr) {
            return;
        }
        ans.push_back(to_string(node->val));
        serializeHelper(node->left, ans);
        serializeHelper(node->right, ans);
    }

    // Helper function to join vector elements with a delimiter
string join(const vector<string>& vec, const string& delimiter) {
    if (vec.empty()) return "";

    string result = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        result += delimiter + vec[i];
    }
    return result;
}

    // Helper function to split a string into integers
    vector<int> splitToInts(const string& str, char delimiter) {
        vector<int> result;
        istringstream iss(str);
        string token;
        while (getline(iss, token, delimiter)) {
            result.push_back(stoi(token));
        }
        return result;
    }

    // Helper function to deserialize the vector of integers
    TreeNode* deserializeHelper(vector<int>& values, int lower, int upper) {
        if (values.empty()) return nullptr;
        int rootValue = values.front();
        if (rootValue < lower || rootValue > upper) 
        return nullptr;

        values.erase(values.begin());
        TreeNode* root = new TreeNode(rootValue);
        root->left = deserializeHelper(values, lower, rootValue);
        root->right = deserializeHelper(values, rootValue, upper);
        return root;
    }
};

// Function to print a tree (pre-order traversal) - for testing
void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

// Example usage
int main() {
    Codec codec;

    // Example tree: 
    //     1
    //    / \
    //   2   3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Serialize
    string serialized = codec.serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    // Deserialize
    TreeNode* deserialized = codec.deserialize(serialized);
    cout << "Deserialized tree (pre-order): ";
    printTree(deserialized);
    cout << endl;

    return 0;
}
