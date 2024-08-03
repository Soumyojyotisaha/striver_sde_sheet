#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(const vector<int>& n, int t) {
        int l = 0;
        int r = n.size() - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (t == n[m]) {
                return m;
            }

            // Left sorted
            if (n[l] <= n[m]) {
                if (t > n[m] || t < n[l]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } 
            // Right sorted
            else {
                if (t < n[m] || t > n[r]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        
        return -1;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Rotated sorted array
    int target = 0;

    int result = solution.search(nums, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
