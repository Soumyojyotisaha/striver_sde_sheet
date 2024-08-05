#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>counter;
        for(auto&v:arr) 
        {
        counter[v]++;
        }
        for(auto&v:arr)
        if(counter[v]==1)
        {
            --k;
            if(k==0)
            return v;
        }
            return "";
    }

};

int main()
{
    Solution sol;
    vector<string>arr={"d","b","c","b","c","a"};
    int k=2;
    string result=sol.kthDistinct(arr,k);
    cout<<result<<" ";
    cout<<endl;

    return 0;
}