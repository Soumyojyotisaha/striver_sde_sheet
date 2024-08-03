#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int tsum = nums[i] + nums[l] + nums[r];
                if (tsum > 0) {
                    --r;
                } else if (tsum < 0) {
                    ++l;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    while (l < r && nums[l] == nums[l - 1]) {
                        ++l;
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    // Find all unique triplets that sum to zero
    vector<vector<int>> result = solution.threeSum(nums);

    // Output the result
    cout << "Unique triplets that sum to zero are:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
