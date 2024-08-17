#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nge(const vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(nums[i]);
        }
        
        return nge;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {5, 7, 1, 2, 6, 0};
    vector<int> res = obj.nge(nums);

    cout << "The next greater elements are: ";
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
