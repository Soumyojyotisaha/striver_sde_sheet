#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
int getsum(int a,int b)
{
    if(b==0)
    return a;

    int sum=a^b;
    int cr=(unsigned int)(a & b)<<1;
    return getsum(sum,cr);
}
};
int main()
{
    Solution sol;
    int a=6;
    int b=10;
    int res=sol.getsum(a,b);
    cout<<res<<endl;
    return 0;
}