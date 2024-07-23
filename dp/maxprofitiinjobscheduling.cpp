#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int i, vector<vector<int>>& job, vector<int>& starttime, int n, vector<int>& dp) {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int index = lower_bound(starttime.begin(), starttime.end(), job[i][1]) - starttime.begin();
        int pick = job[i][2] + find(index, job, starttime, n, dp);
        int notpick = find(i + 1, job, starttime, n, dp);
        return dp[i] = max(pick, notpick);
    }

    int jobSchedule(vector<int>& starttime, vector<int>& endtime, vector<int>& profit) {
        int n = starttime.size();
        vector<vector<int>> job;
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++) {
            job.push_back({starttime[i], endtime[i], profit[i]});
        }
        sort(job.begin(), job.end());
        vector<int> sortedStarttime;
        for (int i = 0; i < n; i++) {
            sortedStarttime.push_back(job[i][0]);
        }
        return find(0, job, sortedStarttime, n, dp);
    }
};

int main() {
    vector<int> starttime = {1, 2, 3, 3};
    vector<int> endtime = {3, 4, 5, 6};
    vector<int> profit = {50, 10, 40, 70};

    Solution sol;
    cout << "Max result: " << sol.jobSchedule(starttime, endtime, profit) << endl;
    return 0;
}
