#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int f = nums.size() - 1; // Initialize the farthest index to the last index of the array

        // Traverse the array from the end to the start
        for (int i = nums.size() - 1; i >= 0; --i) {
            // If the current index plus its value is greater than or equal to the farthest index
            if (i + nums[i] >= f) {
                // Update the farthest index to the current index
                f = i;
            }
        }

        // If the farthest index is 0, it means we can reach the end
        return f == 0;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Can jump (example 1): " << (sol.canJump(nums1) ? "true" : "false") << endl;

    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Can jump (example 2): " << (sol.canJump(nums2) ? "true" : "false") << endl;

    return 0;
}
