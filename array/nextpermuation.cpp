#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int infpnt = -1;
        
        // Find the first number that is not in increasing order from the end
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                infpnt = i;
                break;
            }
        }
        
        if (infpnt == -1) {
            // If no such number is found, the array is sorted in descending order
            // Simply reverse it to get the smallest permutation
            reverse(nums.begin(), nums.end());
        } else {
            // Find the smallest number larger than nums[infpnt] to the right of it
            for (int j = n - 1; j > infpnt; --j) {
                if (nums[j] > nums[infpnt]) {
                    swap(nums[j], nums[infpnt]);
                    break;
                }
            }
            // Reverse the rest of the array after the inflection point
            reverse(nums.begin() + infpnt + 1, nums.end());
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};

    cout << "Original: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    solution.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
