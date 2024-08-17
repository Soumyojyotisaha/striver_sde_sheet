#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0;
        int down = n - 1;

        // Step 1: Find the candidate for the celebrity
        while (top < down) {
            if (mat[top][down] == 1) {
                // top knows down, so top cannot be the celebrity
                top++;
            } else {
                // top does not know down, so down cannot be the celebrity
                down--;
            }
        }

        // Step 2: Verify the candidate
        int candidate = top;
        
        // Check if the candidate is known by everyone and knows no one
        for (int i = 0; i < n; ++i) {
            if (i != candidate) {
                if (mat[candidate][i] != 0 || mat[i][candidate] != 1) {
                    return -1; // Not a celebrity
                }
            }
        }
        
        return candidate; // Valid celebrity
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int result = sol.celebrity(mat);
    cout << "Celebrity is at index: " << result << endl;
    return 0;
}
