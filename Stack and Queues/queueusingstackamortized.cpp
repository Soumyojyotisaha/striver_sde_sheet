#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> input, output;

    MyQueue() {}

    void push(int x) {
        cout << "The element pushed is " << x << endl;
        input.push(x);
    }

    int pop() {
        shiftStacks();
        int x = output.top();
        output.pop();
        return x;
    }
     bool empty() {
        if((input.size()+output.size())==0)
        return true;
        else
        return false;
        
    }

    int top() {
        shiftStacks();
        return output.top();
    }

    int size() {
        return input.size() + output.size();
    }

private:
    void shiftStacks() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }
};

int main() {
    MyQueue q;
    q.push(3);
    q.push(4);
    cout << "The element popped is " << q.pop() << endl;
    q.push(5);
    cout << "The top of the queue is " << q.top() << endl;
    cout << "The size of the queue is " << q.size() << endl;
}
