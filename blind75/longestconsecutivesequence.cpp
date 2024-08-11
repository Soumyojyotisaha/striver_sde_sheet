#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ns(nums.begin(), nums.end()); // Insert elements into the set
        int lgt = 0;

        for (int num : nums) {
            // Check if it's the start of a sequence
            if (ns.find(num - 1) == ns.end()) {
                int lth = 0;
                while (ns.find(num + lth) != ns.end()) {
                    lth++;
                }
                lgt = max(lth, lgt);
            }
        }

        return lgt;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = sol.longestConsecutive(nums);
    cout << "The length of the longest consecutive sequence is " << result << endl;
    return 0;
}
