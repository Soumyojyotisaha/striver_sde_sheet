#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr={7,7,7,3,3,9,9,2,2};

    unordered_map<int,int>map;
    for(int num:arr)
    {
        map[num]++;
    }
    for(const auto &pair:map)
    {
        cout<<pair.first<<":"<<pair.second<<endl;
    }
    for(const auto &num:map)
    {
     cout<<num.first<<endl;
    }
    return 0;
}