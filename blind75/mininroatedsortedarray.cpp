#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int findmin(const vector<int>&nums)
    {
        if(nums.empty())

        {
            return -1;
        }
        int ans=nums[0];
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            if(nums[l]<nums[r])
            {
                ans=min(ans,nums[l]);
                break;
            }

            int mid=(l+r)/2;
            ans=min(ans,nums[mid]);

            if(nums[mid]>=nums[l])
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int>nums={3,4,5,1,2};
    cout<<sol.findmin(nums);
    return 0;
}