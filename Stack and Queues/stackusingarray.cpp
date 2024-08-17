#include<bits/stdc++.h>
using namespace std;
class Stack
{
    int size;
    int *arr;
    int top;
public:
    Stack()
    {
        top=-1;
        size=1000;
        arr=new int [size];
    }
    void push(int x)
    {
        top++;
        arr[top]=x;
    }
    int pop()
    {
        if(top==-1)
        {
            return -1;
        }
        else
        {
        int x=arr[top];
        top--;
        return x;
        }
    }
    int Top()
    {
        return arr[top];
    }
    int Size()
    {
        return top+1;

    }
};
int main()
{
    Stack s;
    s.push(6);
    s.push(22);
    s.push(250);
    cout<<s.pop()<<endl;
    cout<<s.Top()<<endl;
    cout<<s.Size()<<endl;
    return 0;
}