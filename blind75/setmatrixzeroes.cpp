#include <iostream>
#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        // Get the number of rows and columns
        int r = matrix.size();
        int c = matrix[0].size();
        
        // Flag to indicate if the first row needs to be zeroed
        bool r0 = false;
        
        // Check for zeroes and mark the first row and column
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0; // Mark the first row
                    if (i > 0) {
                        matrix[i][0] = 0; // Mark the first column
                    } else {
                        r0 = true; // The first row needs to be zeroed
                    }
                }
            }
        }
        
        // Set matrix elements to zero based on markings
        for (int i = 1; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Set the first column to zero if needed
        if (matrix[0][0] == 0) {
            for (int i = 0; i < r; ++i) {
                matrix[i][0] = 0;
            }
        }
        
        // Set the first row to zero if needed
        if (r0) {
            for (int j = 0; j < c; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};

// Helper function to print the matrix
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    Solution solution;
    
    // Initialize the matrix
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 0, 7, 8},
        {9, 10, 11, 12}
    };
    
    std::cout << "Original matrix:\n";
    printMatrix(matrix);
    
    // Apply the setZeroes function
    solution.setZeroes(matrix);
    
    std::cout << "\nMatrix after setZeroes:\n";
    printMatrix(matrix);
    
    return 0;
}
