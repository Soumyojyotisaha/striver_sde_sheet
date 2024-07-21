#include<bits/stdc++.h>
using namespace std;
    int getAns(vector<int>& nums, int n, int ind, int prev_ind, vector<vector<int>>& dp) {
        if (ind == n)
            return 0;

        // Since prev_ind can be -1, we offset it by 1 to handle negative index.
        if (dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];

        int nottake = 0 + getAns(nums, n, ind + 1, prev_ind, dp);
        int take = 0;

        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
            take = 1 + getAns(nums, n, ind + 1, ind, dp);
        }

        return dp[ind][prev_ind + 1] = max(nottake, take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return getAns(nums, n, 0, -1, dp);
    }

// Example usage
int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "The length of the longest increasing subsequence is " << lengthOfLIS(nums) << endl;
    return 0;
}
