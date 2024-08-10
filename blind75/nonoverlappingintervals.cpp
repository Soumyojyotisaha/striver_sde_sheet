#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals based on the end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int ans = 0;
        int e_prev = intervals[0][1]; // End time of the previous interval

        for (int i = 1; i < intervals.size(); ++i) {
            int s_next = intervals[i][0]; // Start time of the next interval
            int e_next = intervals[i][1]; // End time of the next interval

            if (s_next < e_prev) {
                // Overlapping interval detected
                ans++;
                // Update e_prev to be the minimum end time of the overlapping intervals
                e_prev = min(e_next, e_prev);
            } else {
                // No overlap, update e_prev to the end time of the current interval
                e_prev = e_next;
            }
        }

        return ans;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int result = sol.eraseOverlapIntervals(intervals);
    cout << result << endl; // Output should be 1
    return 0;
}
