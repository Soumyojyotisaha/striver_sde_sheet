#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int lengthoflis(vector<int>num)
    {
        vector<int>lis(num.size(),1);
        for(int i=num.size()-1;i>=0;i--)
        {
          for(int j=i+1;j<num.size();++j)
          {
            if(num[i]<num[j])
            {
              lis[i]=max(lis[i],lis[j]+1);
            }
          }
        }
        return *max_element(lis.begin(),lis.end());
    }
};

int main()
{
    Solution sol;
    vector<int>num={10,9,2,5,3,7,101,18};
    int res=sol.lengthoflis(num);

    cout<<res<<endl;
    return 0;
}