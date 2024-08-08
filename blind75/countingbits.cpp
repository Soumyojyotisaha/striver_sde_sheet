#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> dp(n + 1, 0);
        int c = 1;

        for (int i = 1; i <= n; ++i) {
            if (c * 2 == i) {
                c = i;
            }
            dp[i] = 1 + dp[i - c];
        }

        return dp;
    }
};

int main() {
    Solution solution;

    // Define the test case
    int n = 5;

    // Call the countBits method and get the result
    std::vector<int> result = solution.countBits(n);

    // Print the result
    std::cout << "Number of 1 bits in each number from 0 to " << n << ":" << std::endl;
    for (int i = 0; i <= n; ++i) {
        std::cout << "Number " << i << ": " << result[i] << " bits" << std::endl;
    }

    return 0;
}
