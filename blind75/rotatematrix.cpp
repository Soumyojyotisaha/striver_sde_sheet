#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix.size() - 1;

        while (l < r) {
            for (int i = 0; i < r - l; ++i) {
                int t = l;
                int b = r;

                // Store the top-left element in a temporary variable
                int temp = matrix[t][l + i];

                // Move bottom-left to top-left
                matrix[t][l + i] = matrix[b - i][l];

                // Move bottom-right to bottom-left
                matrix[b - i][l] = matrix[b][r - i];

                // Move top-right to bottom-right
                matrix[b][r - i] = matrix[t + i][r];

                // Move the temporary variable to top-right
                matrix[t + i][r] = temp;
            }
            --r;  // Move the right boundary inward
            ++l;  // Move the left boundary inward
        }
    }
};

int main() {
    Solution solution;

    // Define a 3x3 matrix
    vector<vector<int>> matrix = {
        {1, 2, 3, 10},
        {4, 5, 6, 11},
        {7, 8, 9, 12},
        {17, 18, 19, 22}
    };

    cout << "Original matrix:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Rotate the matrix 90 degrees clockwise
    solution.rotate(matrix);

    cout << "Rotated matrix:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
