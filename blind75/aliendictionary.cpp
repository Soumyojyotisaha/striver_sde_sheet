#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string alienOrder(const vector<string>& words) {
        // Create adjacency list
        unordered_map<char, unordered_set<char>> adj;
        for (const auto& w : words) {
            for (char c : w) {
                adj[c]; // Ensure each character is in the adjacency list
            }
        }

        // Build the graph
        for (size_t i = 0; i < words.size() - 1; ++i) {
            const string& w1 = words[i];
            const string& w2 = words[i + 1];
            size_t lmin = min(w1.length(), w2.length());

            if (w1.length() > w2.length() && w1.substr(0, lmin) == w2.substr(0, lmin)) {
                return ""; // Invalid order
            }

            for (size_t j = 0; j < lmin; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        // Perform topological sort
        unordered_map<char, bool> visited; // true = visiting, false = visited
        vector<char> result;
        unordered_map<char, bool> inStack;

        // Depth-first search function
        std::function<bool(char)> dfs = [&](char c) -> bool {
            if (visited.count(c)) {
                return !visited[c];
            }

            visited[c] = true;
            inStack[c] = true;

            for (char neighbor : adj[c]) {
                if (dfs(neighbor)) {
                    return true; // Cycle detected
                }
            }

            inStack[c] = false;
            result.push_back(c);
            return false;
        };

        // Execute DFS for each node
        for (const auto& entry : adj) {
            if (dfs(entry.first)) {
                return ""; // Cycle detected
            }
        }

        reverse(result.begin(), result.end());
        return string(result.begin(), result.end());
    }
};

int main() {
    Solution sol;
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    string order = sol.alienOrder(words);
    
    cout << "Alien Order: " << order << endl;

    return 0;
}
