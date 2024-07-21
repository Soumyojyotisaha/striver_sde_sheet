#include<bits/stdc++.h>
using namespace std;
int maxprod(vector<int>& arr)
{
    int n=arr.size();
    double ans=INT_MIN;
    double pref=1,suff=1;
    for(int i=0;i<n;++i)
    {
        if(pref==0) pref=1;
        if(suff==0) suff=1;
        pref*=arr[i];
        suff*=arr[n-i-1];
        ans=max(ans,max(pref,suff));

    }
    return ans;
}

int main()
{
    vector<int> arr={1, 2, -3, 0, -4, -5};
    cout<<"maxprod is:"<<maxprod(arr);
    return 0;
}