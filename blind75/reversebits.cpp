#include <iostream>
using namespace std;

class Solution {
public:
uint32_t reverse(uint32_t n)
{
    uint32_t ans=0;
    for(int i=0;i<32;i++)
    {
        uint32_t b=(n>>i)&1;
        ans=ans|(b<<(31-i));
    }
    return ans;
}
};
int main()
{
    Solution sol;
    uint32_t num=45618;
    uint32_t res=sol.reverse(num);
    cout<<res<<endl;
    return 0;
}
