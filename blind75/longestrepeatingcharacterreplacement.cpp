#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int charreplace(string s,int k)
    {
        unordered_map<char,int>hm;
        int ans=0;
        int l=0;
        for(int r=0;r<s.length();++r)
        {
            hm[s[r]]++;
        int maxfreq=0;
        for(const auto&pair:hm)
        {
            if(pair.second>maxfreq)
            {
                maxfreq=pair.second;
            }
        }
        while((r-l+1)-maxfreq>k)
        {
          hm[s[l]]--;
          l++;
          maxfreq=0;

          for(const auto&pair:hm)
          {
            if(pair.second>maxfreq)
            {
               maxfreq=pair.second;
            }
          }
        }
        ans=max(ans,r-l+1);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    string s="ABABBA";
    int k=2;
    int result=sol.charreplace(s,k);
    cout<<result<<endl;
    return 0;
}