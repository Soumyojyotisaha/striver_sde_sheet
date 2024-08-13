#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(const string& s) {
        int n = s.size();
        if (n == 0) return 0;

        // dp[i] will hold the number of ways to decode the substring s[i:]
        vector<int> dp(n + 1, 0);
        dp[n] = 1; // Base case: An empty string can be decoded in one way

        // Iterate from the end of the string to the beginning
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i] = 0; // '0' cannot be decoded alone
            } else {
                // Single digit decoding
                dp[i] = dp[i + 1];

                // Two digit decoding
                if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))) {
                    dp[i] += dp[i + 2];
                }
            }
        }

        return dp[0];
    }
};

// Example usage
int main() {
    Solution solution;
    string s = "226";
    cout << "Number of ways to decode '" << s << "': " << solution.numDecodings(s) << endl; // Output: 3
    return 0;
}
