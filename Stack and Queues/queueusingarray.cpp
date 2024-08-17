#include <iostream>
using namespace std;

class Queue
{
    private:
    int *arr;
    int front,rear,currsize,maxsize;

    public:
    Queue(int maxsize):maxsize(maxsize),front(0),rear(-1),currsize(0)
    {
     arr=new int[maxsize];
    } 
    ~Queue()
    {
        delete[]arr;
    }

    void push(int x)
    {
        if(currsize==maxsize)
        {
        cout<<"overflow"<<endl;
        exit(1);
        }
        rear=(rear+1)%maxsize;
        arr[rear]=x;
        currsize++;
        cout<<x<<endl;
    }

    int pop()
    {
    if(currsize==0)
    {
        return -1;
    }
    int popped=arr[front];
    front=(front+1)%maxsize;
    currsize--;
    return popped;
    }
    int top()
    {
    if(currsize==0)
    {
        return -1;
    }
    return arr[front];
    }
    int Size()
    {
     return currsize;
    }
};

int main()
{
    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "The peek of the queue before deleting any element " << q.top() << endl;
    cout << "The size of the queue before deletion " << q.Size() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.top() << endl;
    cout << "The size of the queue after deleting an element " << q.Size() << endl;

    return 0;
}