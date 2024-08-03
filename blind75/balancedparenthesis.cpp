#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(const string& s) {
        stack<char> stk;
        unordered_map<char, char> hm = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char p : s) {
            if (hm.find(p) != hm.end()) {
                // If stack is not empty and top of the stack matches the expected opening bracket
                if (!stk.empty() && stk.top() == hm[p]) {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                // Push the opening bracket onto the stack
                stk.push(p);
            }
        }

        // Return true if stack is empty, meaning all opening brackets have been matched
        return stk.empty();
    }
};

int main() {
    Solution solution;

    // Test cases
    string test1 = "()[]{}";
    string test2 = "(]";
    string test3 = "([)]";
    string test4 = "{[]}";

    // Validate the strings
    cout << "Test case 1: " << (solution.isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test case 2: " << (solution.isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test case 3: " << (solution.isValid(test3) ? "Valid" : "Invalid") << endl;
    cout << "Test case 4: " << (solution.isValid(test4) ? "Valid" : "Invalid") << endl;

    return 0;
}
