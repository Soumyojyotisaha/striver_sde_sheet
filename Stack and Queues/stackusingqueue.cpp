#include<bits/stdc++.h>
using namespace std;
class Stack
{
queue<int>q;
public:
void push(int x)
{
int s=q.size();
q.push(x);
for(int i=0;i<=s-1;i++)
{
    q.push(q.front());
    q.pop();
}
}
int pop()
{
int n=q.front();
q.pop();
return n;
}
int Top()
{
return q.front();
}
int Size()
{
return q.size();
}
};
int main()
{
    Stack s;
    s.push(3);
  s.push(2);
  s.push(4);
  s.push(1);
  cout << "Top of the stack: " << s.Top() << endl;
  cout << "Size of the stack before removing element: " << s.Size() << endl;
  cout << "The deleted element is: " << s.pop() << endl;
  cout << "Top of the stack after removing element: " << s.Top() << endl;
  cout << "Size of the stack after removing element: " << s.Size();

}