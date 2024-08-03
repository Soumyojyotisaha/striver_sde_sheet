#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;

        for (const string& str : strs) {
            vector<int> cnt(26, 0); // a-z

            // Count the frequency of each character
            for (char ch : str) {
                cnt[ch - 'a']++;
            }

            // Create a key based on character counts
            string key;
            for (int i : cnt) {
                key += to_string(i) + "#";
            }

            // Group anagrams together using the key
            ans[key].push_back(str);
        }

        // Collect results into a vector of vectors
        vector<vector<string>> result;
        for (const auto& pair : ans) {
            result.push_back(pair.second);
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Group anagrams
    vector<vector<string>> result = solution.groupAnagrams(strs);

    // Print grouped anagrams
    for (const auto& group : result) {
        for (const string& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
