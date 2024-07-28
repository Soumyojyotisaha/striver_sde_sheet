#include <iostream>
#include <string>
using namespace std;

const int CHAR = 256;

int leftrep(string str) {
    int count[CHAR] = {0};
    
    // Count occurrences of each character
    for (int i = 0; i < str.length(); i++) {
        count[str[i]]++;
    }
    
    // Find the leftmost character that repeats
    for (int i = 0; i < str.length(); i++) {
        if (count[str[i]] > 1) {
            return i;
        }
    }
    
    return -1; // If no repeating character is found
}

int main() {
    string str = "soumyojyotisaha";
    int index = leftrep(str);
    
    if (index != -1) {
        cout << "The leftmost repeating character is '" << str[index] << "' at index " << index << endl;
    } else {
        cout << "No repeating characters found." << endl;
    }
    
    return 0;
}
