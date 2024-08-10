#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:

    bool validtree(int n,const vector<vector<int>>&edges)
    {
        if(n==0)
        {
            return true;
        }
        unordered_map<int,vector<int>>map;
        for(const auto&edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            map[u].push_back(v);
            map[v].push_back(u);

        }
        unordered_set<int>visited;

        if(!dfs(0,-1,map,visited))
        {
            return false;
        }
        return visited.size()==n;
    }

    private:
    bool dfs(int node,int parent,const unordered_map<int,vector<int>>&map,unordered_set<int>&visited)
    {
        if(visited.count(node))
        {
            return false;
        }
        visited.insert(node);
        for(int neighbor:map.at(node))
        {
           if(neighbor==parent)
           {
            continue;
           } 
           if(!dfs(neighbor,node,map,visited))
           {
            return false;
           }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    int n = 5;

    bool result = sol.validtree(n, edges);
    cout << (result ? "The graph is a valid tree." : "The graph is not a valid tree.") << endl;

    return 0;
}