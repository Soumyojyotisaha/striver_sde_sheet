#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int> nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        // Handle the two scenarios:
        // 1. Exclude the last house
        // 2. Exclude the first house
        return max(
            hr1(vector<int>(nums.begin(), nums.end() - 1)),
            hr1(vector<int>(nums.begin() + 1, nums.end()))
        );
    }
    
private:
    int hr1(const vector<int>& nums) {
        int r1 = 0, r2 = 0;
        for (int n : nums) {
            int t = max(n + r1, r2);
            r1 = r2;
            r2 = t;
        }
        return r2;
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<int> test1 = {2, 3, 2}; // Expected output: 3 (Robbing house 2)
    vector<int> test2 = {1, 2, 3, 1}; // Expected output: 4 (Robbing houses 1 and 3)
    vector<int> test3 = {10, 20, 30, 40, 50}; // Expected output: 90 (Robbing houses 1, 3, and 5)
    vector<int> test4 = {2, 7, 9, 3, 1}; // Expected output: 12 (Robbing houses 1, 3, and 5)

    cout << "Test case 1: " << solution.rob(test1) << endl;
    cout << "Test case 2: " << solution.rob(test2) << endl;
    cout << "Test case 3: " << solution.rob(test3) << endl;
    cout << "Test case 4: " << solution.rob(test4) << endl;

    return 0;
}
