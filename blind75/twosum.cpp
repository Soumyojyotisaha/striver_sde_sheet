#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> hashmap; // value : index
        
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            int diff = target - n;

            if (hashmap.find(diff) != hashmap.end()) {
                return {hashmap[diff], i};
            }

            hashmap[n] = i;
        }

        return {}; // Return an empty vector if no solution is found
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Find two numbers that add up to the target
    vector<int> result = solution.twoSum(nums, target);

    // Output the result
    if (!result.empty()) {
        cout << "Indices of the numbers that add up to " << target << " are: ";
        cout << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two numbers add up to the target." << endl;
    }

    return 0;
}
