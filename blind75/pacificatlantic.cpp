#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        if (h.empty() || h[0].empty()) {
            return {}; // Return empty if input is invalid
        }

        int rows = h.size();
        int cols = h[0].size();
        set<pair<int, int>> p, a; // Sets for Pacific and Atlantic reachable coordinates
        vector<vector<int>> ans; // Result vector

        // Run DFS from Pacific Ocean (top row and left column)
        for (int c = 0; c < cols; ++c) {
            dfs(0, c, p, h[0][c], h);             // Top row
            dfs(rows - 1, c, a, h[rows - 1][c], h); // Bottom row
        }

        // Run DFS from Atlantic Ocean (left column and right column)
        for (int r = 0; r < rows; ++r) {
            dfs(r, 0, p, h[r][0], h);             // Left column
            dfs(r, cols - 1, a, h[r][cols - 1], h); // Right column
        }

        // Find coordinates that can reach both oceans
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (p.count({r, c}) && a.count({r, c})) {
                    ans.push_back({r, c}); // Add to result if reachable by both oceans
                }
            }
        }

        return ans; // Return the result
    }

    // Depth-first search (DFS) function
    void dfs(int r, int c, set<pair<int, int>>& vs, int prev_h, const vector<vector<int>>& h) {
        // Check for base cases: out of bounds, already visited, or height condition not met
        if (r < 0 || c < 0 || r >= h.size() || c >= h[0].size() || h[r][c] < prev_h || vs.count({r, c})) {
            return; // Return early if any base case is met
        }

        vs.insert({r, c}); // Mark the cell as visited

        // Explore the four possible directions
        dfs(r + 1, c, vs, h[r][c], h); // Down
        dfs(r - 1, c, vs, h[r][c], h); // Up
        dfs(r, c + 1, vs, h[r][c], h); // Right
        dfs(r, c - 1, vs, h[r][c], h); // Left
    }
};

int main() {
    Solution solution;

    // Example input
    vector<vector<int>> h = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    // Call the pacificAtlantic method and get the result
    vector<vector<int>> result = solution.pacificAtlantic(h);

    // Print the result
    cout << "Cells that can flow to both Pacific and Atlantic oceans:\n";
    for (const auto& cell : result) {
        cout << "[" << cell[0] << ", " << cell[1] << "]\n";
    }

    return 0;
}
