#include <iostream>
using namespace std;

class Solution {
public:
    // Method 1: Count 1 bits by checking each bit
    int hammingWeightMethod1(uint32_t n) {
        int ans = 0;
        while (n) {
            ans += n % 2;
            n = n >> 1;
        }
        return ans;
    }
    
    // Method 2: Brian Kernighan's algorithm
    // int hammingWeightMethod2(uint32_t n) {
    //     int ans = 0;
    //     while (n) {
    //         n &= (n - 1); // Remove the lowest set bit
    //         ans += 1;
    //     }
    //     return ans;
    // }
};

int main() {
    Solution sol;
    uint32_t num = 0b00000000000000000000000000001011; // Example number, binary 00000000000000000000000000001011 (decimal 11)

    // Test Method 1
    int result1 = sol.hammingWeightMethod1(num);
    cout << "Method 1: Number of 1 bits = " << result1 << endl;
    
    // // Test Method 2
    // int result2 = sol.hammingWeightMethod2(num);
    // cout << "Method 2: Number of 1 bits = " << result2 << endl;

    return 0;
}
