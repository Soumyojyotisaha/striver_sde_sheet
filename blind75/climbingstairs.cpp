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
        
        for (int i = n-2; i > 0; --i) 
        {
            int t = f+s; 
            s=f;
            f--;
            s--;
            f=t;
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
