#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;
        
        for (int num : nums) {
            if (currSum < 0) {
                currSum = 0;
            }
            currSum += num;
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};

int main() {
    // Example usage of the Solution class
    Solution solution;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example input

    int result = solution.maxSubArray(nums);
    cout << "The maximum subarray sum is: " << result << endl;

    return 0;
}
