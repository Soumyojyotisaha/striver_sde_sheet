#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        if (prices.empty()) return 0;

        int l = 0;  // Left pointer (buy day)
        int r = 1;  // Right pointer (sell day)
        int maxProfit = 0;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                // Calculate profit
                int profit = prices[r] - prices[l];
                maxProfit = max(maxProfit, profit);
            } else {
                // Update the buy day to the current sell day
                l = r;
            }
            // Move the sell day forward
            r++;
        }

        return maxProfit;
    }
};

// Helper function to test the solution
int main() {
    Solution sol;

    vector<int> prices = {7, 1, 5, 3, 6, 4};  // Example prices
    int result = sol.maxProfit(prices);

    cout << "Maximum Profit: " << result << endl;

    return 0;
}
