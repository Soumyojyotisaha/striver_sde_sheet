#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& n, int k) {
        unordered_map<int, int> cnt;
        for (int num : n) {
            cnt[num]++;
        }
        vector<vector<int>> f(n.size() + 1);
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
    int num = it->first;       // Access the key
    int frequency = it->second; // Access the value
    f[frequency].push_back(num);
}

        vector<int> ans;
        for (int i = f.size() - 1; i > 0; --i) {
            for (int num : f[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans; // In case k is larger than the number of unique elements
    }
};

int main() {
    Solution solution;

    // Define the test case
    vector<int> n = {1, 1, 1, 2, 2, 3};
    int k = 2;

    // Call the topKFrequent method and get the result
    vector<int> result = solution.topKFrequent(n, k);

    // Print the result
    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
