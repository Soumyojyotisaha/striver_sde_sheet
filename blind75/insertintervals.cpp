#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        int i = 0;

        // Add all intervals that come before the new interval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            ++i;
        }

        // Merge overlapping intervals with the new interval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        result.push_back(newInterval);

        // Add all intervals that come after the new interval
        while (i < n) {
            result.push_back(intervals[i]);
            ++i;
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    vector<vector<int>> result1 = sol.insert(intervals1, newInterval1);

    cout << "Merged Intervals for Example 1: ";
    for (const auto& interval : result1) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    // Example 2
    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};
    vector<vector<int>> result2 = sol.insert(intervals2, newInterval2);

    cout << "Merged Intervals for Example 2: ";
    for (const auto& interval : result2) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
