#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int lcs(const string&t1,const string&t2)
    {
    int m=t1.length();
    int n=t2.length();
    vector<vector<int>>matrix(m+1,vector<int>(n+1,0));

    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(t1[i]==t2[j])
            {
                matrix[i][j]=1+matrix[i+1][j+1];
            }
            else
            {
                matrix[i][j]=max(matrix[i][j+1],matrix[i+1][j]);
            }
        }
    }
    return matrix[0][0];
    }
};
int main()
{
    Solution sol;
    string t1 = "abcde";
    string t2 = "ace";
    
    int result = sol.lcs(t1, t2);
    cout << "Length of Longest Common Subsequence: " << result << endl;
    
    return 0;
}