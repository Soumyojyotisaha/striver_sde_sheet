#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // Base cases
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int f = 1; // Number of ways to climb to the previous step
        int s = 1; // Number of ways to climb to the step before the previous one
        
        for (int i = 1; i < n; ++i) {
            int t = f; // Temporary store of previous step's number of ways
            f = f + s; // Number of ways to climb to the current step
            s = t; // Update previous step's number of ways
        }
        
        return f;
    }
};

int main() {
    Solution solution;
    int n = 5; // Example number of steps
    
    cout << "Number of ways to climb " << n << " stairs: " << solution.climbStairs(n) << endl;
    
    return 0;
}
