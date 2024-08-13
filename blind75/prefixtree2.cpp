#include <bits/stdc++.h>
using namespace std;

// Define the TrieNode structure
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool eow; // End of word marker

    TrieNode() : eow(false) {}
};

// Define the WordDictionary class
class WordDictionary {
private:
    TrieNode* root;

    // Recursive function for DFS search
    bool dfs(const string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->eow;
        }
        
        char c = word[index];
        if (c == '.') {
            for (auto& [_, child] : node->children) {
                if (dfs(word, index + 1, child)) {
                    return true;
                }
            }
            return false;
        } else {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            return dfs(word, index + 1, node->children[c]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void addWord(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->eow = true;
    }

    // Search for a word in the trie with support for wildcards
    bool search(const string& word) {
        return dfs(word, 0, root);
    }

    // Destructor to free allocated memory
    ~WordDictionary() {
        function<void(TrieNode*)> destroy = [&](TrieNode* node) {
            for (auto& [_, child] : node->children) {
                destroy(child);
            }
            delete node;
        };
        destroy(root);
    }
};

// Example usage
int main() {
    WordDictionary obj;

    obj.addWord("bad");
    obj.addWord("dad");
    obj.addWord("mad");

    cout << boolalpha; // Print boolean values as true/false
    cout << "Search 'pad': " << obj.search("pad") << endl; // Output: false
    cout << "Search 'bad': " << obj.search("bad") << endl; // Output: true
    cout << "Search '.ad': " << obj.search(".ad") << endl; // Output: true
    cout << "Search 'b..': " << obj.search("b..") << endl; // Output: true

    return 0;
}
