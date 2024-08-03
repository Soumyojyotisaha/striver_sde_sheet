#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(const string& s) {
        string p = "";
        int plen = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Odd length palindrome check
            int l = i, r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (r - l + 1 > plen) {
                    p = s.substr(l, r - l + 1);
                    plen = r - l + 1;
                }
                --l;
                ++r;
            }

            // Even length palindrome check
            l = i, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (r - l + 1 > plen) {
                    p = s.substr(l, r - l + 1);
                    plen = r - l + 1;
                }
                --l;
                ++r;
            }
        }

        return p;
    }
};

int main() {
    Solution solution;

    // Example input
    string s = "babad";

    // Find the longest palindromic substring
    string result = solution.longestPalindrome(s);

    // Output the result
    cout << "Longest palindromic substring is: " << result << endl;

    return 0;
}
