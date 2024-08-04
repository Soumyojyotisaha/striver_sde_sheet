#include<bits/stdc++.h>
using namespace std;
vector<int> topkelements(vector<int>&nums,int k)
{
    unordered_map<int,int>frequencymap;
    for(int num:nums)
    {
        frequencymap[num]++;
    }
    vector<vector<int>> bucket(nums.size()+1);
    for(const auto&entry:frequencymap)
    {
        int num=entry.first;
        int freq=entry.second;
        bucket[freq].push_back(num);
    }
    
    vector<int> topk;
    for(int i=bucket.size()-1;i>=0 && topk.size()<k;--i)
    {
        if(!bucket[i].empty())
        {
            topk.insert(topk.end(), bucket[i].begin(), bucket[i].end());
        }
}
    return vector<int>(topk.begin(),topk.begin()+k);
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topkelements(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}