#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int countComponents(int n, vector<vector<int>> &edges) {
        // Initialize adjacency list for the graph
        vector<vector<int>> adj(n);
        
        // Fill the adjacency list
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Initialize visited vector to track visited nodes
        vector<bool> visited(n, false);
        
        // Helper function to perform DFS
        auto DFS = [&](int start) {
            stack<int> s;
            s.push(start);
            while (!s.empty()) {
                int node = s.top();
                s.pop();
                if (!visited[node]) {
                    visited[node] = true;
                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            s.push(neighbor);
                        }
                    }
                }
            }
        };

        // Count connected components
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                DFS(i);
                ++count;
            }
        }

        return count;
    }
};

int main() {
    // Create an instance of Solution
    Solution solution;

    // Example 1
    int n1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}};
    cout << "Example 1" << endl;
    cout << "Input: " << n1 << " " << "[[0,1], [0,2]]" << endl;
    int result1 = solution.countComponents(n1, edges1);
    cout << "Output: " << result1 << endl;
    cout << endl;

    // Example 2
    int n2 = 6;
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}, {4, 5}};
    cout << "Example 2" << endl;
    cout << "Input: " << n2 << " " << "[[0,1], [1,2], [2,3], [4,5]]" << endl;
    int result2 = solution.countComponents(n2, edges2);
    cout << "Output: " << result2 << endl;

    return 0;
}
