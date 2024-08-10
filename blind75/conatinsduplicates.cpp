#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(const vector<int>& nums) {
        unordered_set<int> hs;
        for (int n : nums) {
            if (hs.find(n) != hs.end()) {
                return true; // Duplicate found
            } else {
                hs.insert(n); // Insert the element if not found
            }
        }
        return false; // No duplicates found
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<int> test1 = {1, 2, 3, 4, 5}; // Expected output: false (no duplicates)
    vector<int> test2 = {1, 2, 3, 2};    // Expected output: true (duplicate 2)
    vector<int> test3 = {5, 5, 5, 5};    // Expected output: true (duplicate 5)
    vector<int> test4 = {};              // Expected output: false (empty vector)

    // Execute and print results for test cases
    cout << "Test case 1: " << (solution.containsDuplicate(test1) ? "true" : "false") << endl;
    cout << "Test case 2: " << (solution.containsDuplicate(test2) ? "true" : "false") << endl;
    cout << "Test case 3: " << (solution.containsDuplicate(test3) ? "true" : "false") << endl;
    cout << "Test case 4: " << (solution.containsDuplicate(test4) ? "true" : "false") << endl;

    return 0;
}
