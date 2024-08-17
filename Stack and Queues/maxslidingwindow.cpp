#include<bits/stdc++.h>
using namespace std;
vector<int> maxsliding(vector<int>&nums,int k)
{
    vector<int>result;
    deque<int>dq;
    for(int i=0;i<nums.size();i++)
    {
        while(!dq.empty() && dq.front()<i-k+1)
        {
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()]<nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1)
        {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}
int main() {
    int k = 3;
    vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    vector<int> ans = maxsliding(arr, k);

    cout << "Maximum element in every " << k << " window:" << endl;
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}