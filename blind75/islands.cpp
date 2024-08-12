#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        unordered_set<int> visited;  // To keep track of visited cells
        int numIslands = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1' && visited.find(r * cols + c) == visited.end()) {
                    bfs(grid, r, c, visited);
                    numIslands++;
                }
            }
        }

        return numIslands;
    }

private:
    void bfs(vector<vector<char>>& grid, int startRow, int startCol, unordered_set<int>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        q.push({startRow, startCol});
        visited.insert(startRow * cols + startCol);

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            int row = current.first;
            int col = current.second;

            for (const auto& direction : directions) {
                int dr = direction.first;
                int dc = direction.second;
                int newRow = row + dr;
                int newCol = col + dc;
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                    grid[newRow][newCol] == '1' && visited.find(newRow * cols + newCol) == visited.end()) {
                    q.push({newRow, newCol});
                    visited.insert(newRow * cols + newCol);
                }
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    int result = sol.numIslands(grid);
    cout << "Number of islands: " << result << endl;
    return 0;
}
