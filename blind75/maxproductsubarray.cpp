#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(const vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int ans = nums[0];
        int mi = 1;
        int ma = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            int temp = ma * nums[i];
            ma = max(nums[i] * ma, max(nums[i] * mi, nums[i]));
            mi = min(nums[i] * mi, min(temp, nums[i]));
            ans = max(ans, ma);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, -2, 4};
    int res = sol.maxProduct(nums);
    cout << "Result is: " << res << endl;
    return 0;
}
