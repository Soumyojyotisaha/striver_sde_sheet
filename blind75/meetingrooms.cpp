#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Interval {
    int start;
    int end;
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    vector<Interval> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    bool result1 = sol.canAttendMeetings(intervals1);
    cout << (result1 ? "true" : "false") << endl;

    vector<Interval> intervals2 = {{5, 8}, {9, 15}};
    bool result2 = sol.canAttendMeetings(intervals2);
    cout << (result2 ? "true" : "false") << endl;

    return 0;
}
