#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long>> dp(n, vector<long>(amount + 1, INT_MAX)); // Initialize dp with a large value (INT_MAX)

        // Base case: If we need to make amount 0, we need 0 coins
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }

        // Fill the first row (only using the first type of coin)
        for (int i = 1; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = i / coins[0]; // Minimum coins needed if the amount is divisible by coins[0]
            }
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= amount; target++) {
                long notTake = dp[ind - 1][target]; // Not taking the current coin

                long take = INT_MAX;
                if (coins[ind] <= target) {
                    take = dp[ind][target - coins[ind]] + 1; // Taking the current coin and adding 1 to the count
                }

                dp[ind][target] = min(take, notTake); // Take the minimum of taking or not taking the current coin
            }
        }

        int result = dp[n - 1][amount];
        return (result == INT_MAX) ? -1 : result; // If result is still INT_MAX, it means no solution was found
    }
};

int main() {
    Solution solution;
    vector<int> coins = {1, 2, 5}; // Example coin denominations
    int amount = 11; // Example amount to make

    int result = solution.coinChange(coins, amount);
    
    if (result != -1) {
        cout << "The minimum number of coins to make " << amount << " is " << result << "." << endl;
    } else {
        cout << "It is not possible to make " << amount << " with the given coin denominations." << endl;
    }

    return 0; // Return 0 to indicate successful program execution
}
