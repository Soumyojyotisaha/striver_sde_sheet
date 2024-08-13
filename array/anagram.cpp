#include <iostream>
#include <string>
using namespace std;

bool anagram(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false; // Strings of different lengths cannot be anagrams
    }

    int count[256] = {0}; // Assuming ASCII character set
    for (int i = 0; i < s1.length(); i++) {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return false; // If any character count is not zero, they are not anagrams
        }
    }

    return true; // All character counts are zero, they are anagrams
}

int main() {
    string s1 = "listen";
    string s2 = "silent";

    if (anagram(s1, s2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
