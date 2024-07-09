#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) 
        {
            vector<int> v(i + 1, 1);
            for (int j = 1; j < i; j++) 
            {
                v[j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
            ans.push_back(v);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int numRows = 5;
    vector<vector<int>> result = sol.generate(numRows);

    cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
