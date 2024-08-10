#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hm; // To count frequencies of characters
        int ans = 0;
        int l = 0;
        
        for (int r = 0; r < s.length(); ++r) {
            hm[s[r]]++;
            
            // Check if the current window size minus the count of the most frequent character
            // is greater than k
            while ((r - l + 1) - max_element(hm.begin(), hm.end(), [](const pair<char, int>& a, const pair<char, int>& b) 
            {
            return a.second < b.second;
            })->second > k) 
            {
                hm[s[l]]--;
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};

// Example usage
int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    int result = sol.characterReplacement(s, k);
    cout << result << endl; // Output should be 4
    return 0;
}
