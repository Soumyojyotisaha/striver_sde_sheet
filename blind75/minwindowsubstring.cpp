#include <iostream>
#include <unordered_map>
#include <climits> // For INT_MAX
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> ct, sw;
        for (char c : t) {
            ct[c]++;
        }

        int ardy = 0, req = ct.size();
        pair<int, int> ans(-1, -1);
        int alen = INT_MAX;

        int l = 0; // left pointer

        for (int r = 0; r < s.size(); ++r) {
            char c = s[r];
            sw[c]++;

            if (ct.count(c) && sw[c] == ct[c]) {
                ardy++;
            }

            while (ardy == req) {
                if ((r - l + 1) < alen) {
                    ans = {l, r};
                    alen = r - l + 1;
                }
                sw[s[l]]--;
                if (ct.count(s[l]) && sw[s[l]] < ct[s[l]]) {
                    ardy--;
                }
                l++;
            }
        }

        if (ans.first == -1) {
            return "";
        } else {
            return s.substr(ans.first, ans.second - ans.first + 1);
        }
    }
};

int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum window substring: " << sol.minWindow(s, t) << endl;
    return 0;
}
