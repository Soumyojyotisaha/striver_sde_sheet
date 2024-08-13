#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
    unordered_map<char,TrieNode*>children;
    bool eow;

    TrieNode():eow(false){}
};
class Trie
{
    private:
    TrieNode*root;
    public:
    Trie()
    {
        root=new TrieNode();
    }

    void insert(const string&word)
    {
        TrieNode*curr=root;
        for(char c:word)
        {
            if(curr->children.find(c)==curr->children.end())
            {
                curr->children[c]=new TrieNode();
            }
            curr=curr->children[c];
        }
        curr->eow=true;
    }

    bool search(const string&word)
    {
        TrieNode*curr=root;
        for(char c:word)
        {
            if(curr->children.find(c)==curr->children.end())
            {
                return false;
            }
            curr=curr->children[c];
        }
        return curr->eow;
    }

    bool startswith(const string& prefix)
    {
        TrieNode*curr=root;
        for(char c: prefix)
        {
            if(curr->children.find(c)==curr->children.end())
            {
                return false;
            }
            curr=curr->children[c];

        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    cout<<boolalpha;
    cout << "Search 'apple': " << trie.search("apple") << endl;
    cout << "Search 'app': " << trie.search("app") << endl;   
    cout << "Starts with 'app': " << trie.startswith("app") << endl; 
    cout << "Starts with 'appl': " << trie.startswith("appl") << endl;
    cout << "Starts with 'b': " << trie.startswith("b") << endl; 

    return 0;

}