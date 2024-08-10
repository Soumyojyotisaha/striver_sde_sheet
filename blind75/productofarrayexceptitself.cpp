#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        int pre = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] = pre;
            pre *= nums[i];
        }
        
        int pos = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= pos;
            pos *= nums[i];
        }
        
        return ans;
    }
};

// Function to print the result vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Example test case
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = solution.productExceptSelf(nums);

    // Print the result
    cout << "The product of array except self is: ";
    printVector(result);

    return 0;
}
