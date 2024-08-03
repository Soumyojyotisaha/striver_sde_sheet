#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        dfs(candidates, target, 0, combination, result);
        return result;
    }

private:
    void dfs(const vector<int>& candidates, int target, int start, vector<int>& combination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            combination.push_back(candidates[i]);
            // Recur with the same element (i) because we can reuse elements
            dfs(candidates, target - candidates[i], i, combination, result);
            combination.pop_back(); // Backtrack
        }
    }
};

int main() {
    Solution solution;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = solution.combinationSum(candidates, target);

    cout << "Combinations that sum up to " << target << " are:" << endl;
    for (const auto& combination : result) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i < combination.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
