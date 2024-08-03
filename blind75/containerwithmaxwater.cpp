#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(const vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1;

        while (l < r) {
            int ar = (r - l) * min(height[l], height[r]);
            ans = max(ans, ar);

            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // Find the maximum area of water contained
    int result = solution.maxArea(height);

    // Output the result
    cout << "Maximum area of water contained is: " << result << endl;

    return 0;
}
