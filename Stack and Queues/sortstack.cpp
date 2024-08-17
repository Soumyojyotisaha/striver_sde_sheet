#include <iostream>
#include <stack>

using namespace std;

// Function to insert an element into a sorted stack
void insertSorted(stack<int> &s, int element) {
    // Base case: if stack is empty or element is greater than top of stack
    if (s.empty() || s.top() <= element) {
        s.push(element);
        return;
    }

    // Pop the top element and recur
    int topElement = s.top();
    s.pop();
    insertSorted(s, element);

    // Push the top element back
    s.push(topElement);
}

// Function to sort the stack using recursion
void sortStack(stack<int> &s) {
    // Base case: If stack is empty or has one element
    if (s.empty()) {
        return;
    }

    // Pop the top element
    int topElement = s.top();
    s.pop();

    // Recursively sort the remaining stack
    sortStack(s);

    // Insert the popped element in sorted stack
    insertSorted(s, topElement);
}

// Function to print the stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    // Hardcoded stack values
    stack<int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    // Sort and print the stack
    sortStack(s);
    printStack(s);

    return 0;
}
