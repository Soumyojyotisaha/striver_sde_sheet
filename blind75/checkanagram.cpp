#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths differ, they cannot be anagrams
        if (s.size() != t.size()) {
            return false;
        }

        // Frequency maps for both strings
        unordered_map<char, int> cs, ct;

        // Count frequencies of characters
        for (int i = 0; i < s.size(); ++i) {
            cs[s[i]]++;
            ct[t[i]]++;
        }

        // Compare frequency maps
        for (auto& pair : cs) {
            if (ct[pair.first] != pair.second) {
                return false;
            }
        }

        return true;
    }
};

// Function to test the isAnagram method
int main() {
    Solution solution;

    // Test cases
    string s1 = "anagram";
    string t1 = "nagaram";
    cout << "Are \"" << s1 << "\" and \"" << t1 << "\" anagrams? " << (solution.isAnagram(s1, t1) ? "Yes" : "No") << endl;

    string s2 = "rat";
    string t2 = "car";
    cout << "Are \"" << s2 << "\" and \"" << t2 << "\" anagrams? " << (solution.isAnagram(s2, t2) ? "Yes" : "No") << endl;

    return 0;
}
