#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(const vector<string>& strs) {
        string ans;
        for (const auto& s : strs) {
            ans += to_string(s.length()) + "$" + s;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(const string& str) {
        vector<string> ans;
        int i = 0;
        
        while (i < str.size()) {
            int j = i;
            while (str[j] != '$') {
                j++;
            }
            int len = stoi(str.substr(i, j - i));
            ans.push_back(str.substr(j + 1, len));
            i = j + 1 + len;
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"hello", "world"};
    
    // Encode
    string encoded = sol.encode(strs);
    cout << "Encoded: " << encoded << endl;
    
    // Decode
    vector<string> decoded = sol.decode(encoded);
    
    // Print decoded result
    cout << "Decoded: ";
    for (const auto& s : decoded) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
