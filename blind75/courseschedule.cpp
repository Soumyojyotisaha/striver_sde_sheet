#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution
{
    public:
    bool canfinish(int n,vector<vector<int>>&preq)
    {
        unordered_map<int,vector<int>>graph;
        for(const auto&pq:preq)
        {
            int course=pq[0];
            int preqs=pq[1];
            graph[course].push_back(preqs);
        }

        unordered_set<int>visited;
        unordered_set<int>recursionstack;

        function<bool(int)>dfs=[&](int course)
        {
            if (recursionstack.count(course))
            {
                return false;
            }
            if(visited.count(course))
            {
                return true;
            }
            else
            {
                recursionstack.insert(course);
                visited.insert(course);
            }

            for(int p:graph[course])
            {
                if(!dfs(p))
                return false;
            }

            recursionstack.erase(course);
            return true;
        };
        for(int course=0;course<n;course++)
        {
            if(!dfs(course))
            return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    int n=2;
    vector<vector<int>>preq={{1,0}};

    cout<<(sol.canfinish(n,preq)?"Yes":"No")<<endl;
    return 0;


}