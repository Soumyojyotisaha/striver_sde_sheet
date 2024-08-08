#include <iostream>
#include <vector>

// Assume the Solution class is defined here
class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        // Initialize dp array with amount + 1 (a large number)
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // Base case: 0 coins needed to make amount 0

        // Fill the dp array
        for (int a = 1; a <= amount; ++a) {
            for (int c : coins) {
                if (a - c >= 0) {
                    dp[a] = std::min(dp[a], 1 + dp[a - c]);
                }
            }
        }

        // If dp[amount] is still amount + 1, return -1 (not possible)
        return dp[amount] <= amount ? dp[amount] : -1;
    }
};

int main() {
    Solution solution;

    // Define the test case
    std::vector<int> coins = {1, 2, 5};
    int amount = 11;

    // Call the coinChange method and get the result
    int result = solution.coinChange(coins, amount);

    // Print the result
    std::cout << "Minimum number of coins needed: " << result << std::endl;

    return 0;
}
