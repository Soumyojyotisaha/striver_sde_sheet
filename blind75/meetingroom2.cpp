#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Interval {
public:
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        vector<int> startTimes, endTimes;
        
        // Extract start and end times
        for (const auto& interval : intervals) {
            startTimes.push_back(interval.start);
            endTimes.push_back(interval.end);
        }

        // Sort start and end times
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int rooms = 0, endPtr = 0;
        
        // Iterate through the start times
        for (int startPtr = 0; startPtr < startTimes.size(); ++startPtr) {
            // If the meeting starts before the earliest ending meeting ends
            if (startTimes[startPtr] < endTimes[endPtr]) {
                ++rooms;
            } else {
                // Otherwise, free up a room
                ++endPtr;
            }
        }

        return rooms;
    }
};

// Example usage
int main() {
    Solution sol;

    vector<Interval> intervals = {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
    int result = sol.minMeetingRooms(intervals);
    cout << "Minimum number of meeting rooms required: " << result << endl;

    return 0;
}
