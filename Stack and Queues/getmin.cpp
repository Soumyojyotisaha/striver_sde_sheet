#include<bits/stdc++.h>
using namespace std;
class minstack
{
    public:
    stack<pair<int,int>>st;
void push(int x)
{
    if(st.empty())
    {
        st.push(pair<int,int>(x,x));
    }
    else
    {
    st.push(pair<int,int>(x,min(x,st.top().second))); 
    }
}
  void pop() {
    st.pop();
  }

  // Get the top element of the stack
  int top() {
    return st.top().first;
  }

  // Retrieve the minimum element in the stack
  int getMin() {
    return st.top().second;
  }
};
int main()
{
  minstack ms;
  ms.push(5);
  ms.push(3);
  ms.pop();
  ms.push(-1);
  cout<<ms.getMin()<<endl;
  return 0;  
}