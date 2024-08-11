#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool wordbreak(const string&s ,const vector<string>&wd)
    {
        int n=s.length();
        vector<bool>dp(n+1,false);
        dp[n]=true;

        unordered_set<string>worddict(wd.begin(),wd.end());
        for(int i=n-1;i>=0;--i)
        {
            for(const string&w:worddict)
            {
                int len=w.length();
                if(i+len<=n && s.substr(i,len)==w)
                {
                    dp[i]=dp[i+len];

                }
                if(dp[i])
                break;
            }

        }
        return dp[0];

    }
};

int main() {
    Solution sol;

    // Example string and word dictionary
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    bool result = sol.wordbreak(s, wordDict);

    cout << (result ? "True" : "False") << endl;

    return 0;
}