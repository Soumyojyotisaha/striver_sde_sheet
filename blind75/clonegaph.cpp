#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
struct Node {
    int val;
    vector<Node*> neighbors;
    Node(int x) : val(x) {}
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr; // Handle the case of an empty graph
        
        unordered_map<Node*, Node*> o2n; // Old to new map
        
        // Use a queue for BFS
        queue<Node*> q;
        q.push(node);
        
        // Clone the root node
        Node* newNode = new Node(node->val);
        o2n[node] = newNode;
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            // Iterate over each neighbor of the current node
            for (Node* neighbor : curr->neighbors) {
                // Clone the neighbor if it hasn't been cloned yet
                if (o2n.find(neighbor) == o2n.end()) {
                    o2n[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // Add the cloned neighbor to the current node's neighbors
                o2n[curr]->neighbors.push_back(o2n[neighbor]);
            }
        }
        
        return o2n[node];
    }
};

void printGraph(Node* node, unordered_map<Node*, bool>& visited) {
    if (!node || visited[node]) return;
    visited[node] = true;
    cout << "Node " << node->val << ":";
    for (Node* neighbor : node->neighbors) {
        cout << " " << neighbor->val;
    }
    cout << endl;
    for (Node* neighbor : node->neighbors) {
        printGraph(neighbor, visited);
    }
}

int main() {
    // Creating a sample graph
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    
    n1->neighbors = {n2, n3};
    n2->neighbors = {n1, n4};
    n3->neighbors = {n1, n4};
    n4->neighbors = {n2, n3};
    
    Solution sol;
    Node* clonedGraph = sol.cloneGraph(n1);
    
    // Print the original graph
    cout << "Original Graph:" << endl;
    unordered_map<Node*, bool> visited;
    printGraph(n1, visited);
    
    // Print the cloned graph
    cout << "Cloned Graph:" << endl;
    visited.clear();
    printGraph(clonedGraph, visited);
    
    return 0;
}
