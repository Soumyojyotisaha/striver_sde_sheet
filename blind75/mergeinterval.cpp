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

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Example newInterval for demonstration purposes
        vector<int> newInterval = {4, 8}; // Adjust as needed
        return insert(intervals, newInterval);
    }
};

// Main function for testing
int main() {
    Solution sol;

    // Example input
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 8}; // Example new interval

    vector<vector<int>> result = sol.insert(intervals, newInterval);

    // Print the result
    cout << "Merged Intervals: ";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
