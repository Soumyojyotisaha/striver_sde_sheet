#include<bits/stdc++.h>
using namespace std;
class go 
{
    public:
    int x;
    go(int a)
    {
        x=a;
    }
    go(go&i)
    {
        x=i.x;
    }
};

int main()
{
    go a1(20);
    go a2(a1);
    cout<<a2.x<<endl;
    return 0;
}