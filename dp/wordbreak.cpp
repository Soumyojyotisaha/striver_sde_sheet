#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[301];

    int help(int i, string s, set<string>& wordDict) {
        if (i == s.size())
            return 1;
        string temp;
        if (dp[i] != -1)
            return dp[i];
        for (int j = i; j < s.size(); j++) {
            temp += s[j];
            if (wordDict.find(temp) != wordDict.end()) {
                if (help(j + 1, s, wordDict))
                    return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < wordDict.size(); i++)
            st.insert(wordDict[i]);
        return help(0, s, st);
    }
};

int main() {
    string s = "applespensand";
    vector<string> wordDict = {"leet", "code"};
    Solution sol;
    if (sol.wordBreak(s, wordDict)) {
        cout << "String can be segmented" << endl;
    } else {
        cout << "String cannot be segmented" << endl;
    }
    return 0;
}
