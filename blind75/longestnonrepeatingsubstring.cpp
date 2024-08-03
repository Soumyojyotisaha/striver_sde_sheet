#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        unordered_set<char> charSet;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); ++right) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                ++left;
            }
            charSet.insert(s[right]);
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Example input
    string s = "abcabcbb";

    // Find the length of the longest substring without repeating characters
    int result = solution.lengthOfLongestSubstring(s);

    // Output the result
    cout << "Length of the longest substring without repeating characters is: " << result << endl;

    return 0;
}
