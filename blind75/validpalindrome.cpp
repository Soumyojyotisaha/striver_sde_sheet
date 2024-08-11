#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool isplaindrome(string s)
    {
        string ns="";
        for(char c:s)
        {
            if(isalnum(c))
            {
                ns+=tolower(c);
            }
        }
        int left=0,right=ns.length()-1;
        while(left<right)
        {
            if(ns[left]!=ns[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
int main()
{
    Solution sol;
    string str="A man, A plan ,a canal: Panama";
    bool result=sol.isplaindrome(str);
    cout<<(result?"true":"false")<<endl;
    return 0;
}