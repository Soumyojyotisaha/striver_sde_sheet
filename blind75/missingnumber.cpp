#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(const vector<int>& nums) {
        int n = nums.size();
        int ans = n; // Start with n, as the answer will be in range [0, n]

        for (int i = 0; i < n; ++i) {
            ans += (i - nums[i]); // Adjust the answer based on the formula
        }

        return ans; // The missing number
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 0, 1}; // Example input

    int result = sol.missingNumber(nums);
    cout << "Missing number: " << result << endl;

    return 0;
}
