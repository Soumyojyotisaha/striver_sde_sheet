#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int first = -1;
        int second = -1;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (x == first) {
                count1++;
            } else if (x == second) {
                count2++;
            } else if (count1 == 0) {
                first = x;
                count1 = 1;
            } else if (count2 == 0) {
                second = x;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == first) {
                count1++;
            } else if (nums[i] == second) {
                count2++;
            }
        }
        vector<int> ret;
        if (count1 > n / 3) ret.push_back(first);
        if (count2 > n / 3) ret.push_back(second);
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 3}; // Sample input
    vector<int> result = solution.majorityElement(nums);
    
    cout << "Majority elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
