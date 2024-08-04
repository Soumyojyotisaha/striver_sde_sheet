#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        if (matrix.empty()) return ans;
        
        int l = 0, r = matrix[0].size();
        int t = 0, b = matrix.size();
        
        while (l < r && t < b) {
            // Traverse the top row
            for (int i = l; i < r; ++i) {
                ans.push_back(matrix[t][i]);
            }
            ++t;
            
            // Traverse the right column
            for (int i = t; i < b; ++i) {
                ans.push_back(matrix[i][r - 1]);
            }
            --r;
            
            // Check if there are rows and columns left
            if (!(l < r && t < b)) {
                break;
            }
            
            // Traverse the bottom row
            for (int i = r - 1; i >= l; --i) {
                ans.push_back(matrix[b - 1][i]);
            }
            --b;
            
            // Traverse the left column
            for (int i = b - 1; i >= t; --i) {
                ans.push_back(matrix[i][l]);
            }
            ++l;
        }
        
        return ans;
    }
};

int main() {
    // Example usage of the Solution class
    Solution solution;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = solution.spiralOrder(matrix);
    
    cout << "Spiral order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
