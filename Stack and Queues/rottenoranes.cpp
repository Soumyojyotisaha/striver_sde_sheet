#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int oranges(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Initialize the visited array with all zeros
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        
        // Enqueue all initially rotten oranges and mark them in the `vis` array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2; // Mark this cell as rotten in the `vis` array
                }
            }
        }
        
        int tm = 0; // To track the time taken for all oranges to rot
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            tm = max(tm, t); // Update the maximum time
            
            // Explore the 4 directions (up, right, down, left)
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                // Check if the new position is valid and contains a fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2; // Mark this orange as rotten
                }
            }
        }
        
        // Check if there's any fresh orange left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 2) {
                    return -1; // There are still fresh oranges left
                }
            }
        }
        
        return tm; // Return the maximum time taken for all oranges to rot
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    cout << sol.oranges(grid);
    return 0;
}
