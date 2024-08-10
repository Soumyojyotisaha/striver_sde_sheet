#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>>& board, const string& word)
    {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (dfs(board, word, r, c, 0, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(const vector<vector<char>>& board, const string& word, int r, int c, int index, vector<vector<bool>>& visited) {
        if (index == word.size())
        {
            return true;
        }
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() ||
            board[r][c] != word[index] || visited[r][c])
        {
            return false;
        }

        visited[r][c] = true;

        bool found = dfs(board, word, r + 1, c, index + 1, visited) ||
                     dfs(board, word, r - 1, c, index + 1, visited) ||
                     dfs(board, word, r, c + 1, index + 1, visited) ||
                     dfs(board, word, r, c - 1, index + 1, visited);

        visited[r][c] = false;

        return found;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";

    bool result = sol.exist(board, word);
    cout << (result ? "The word exists in the board." : "The word does not exist in the board.") << endl;

    return 0;
}
