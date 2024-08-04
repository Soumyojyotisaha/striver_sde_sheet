#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a vector to hold the number of paths for the current row
        vector<int> r(n, 1);

        // Iterate through each row, except the first one
        for (int i = 0; i < m - 1; ++i) {
            // Create a temporary vector for the new row
            vector<int> nr(n, 1);

            // Calculate the number of unique paths for each cell in the new row
            for (int j = n - 2; j >= 0; --j) {
                nr[j] = nr[j + 1] + r[j];
            }

            // Move to the next row
            r = nr;
        }

        // The result is the number of unique paths to reach the top-left corner
        return r[0];
    }
};

int main() {
    Solution solution;
    int m = 3;
    int n = 4;
    
    cout << "Unique Paths for a " << m << "x" << n << " grid: " << solution.uniquePaths(m, n) << endl;

    return 0;
}
