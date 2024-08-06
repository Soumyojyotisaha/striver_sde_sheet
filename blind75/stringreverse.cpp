#include <iostream>
#include <vector>
#include <string>

// Function to reverse the order of words in a string
std::string reverseWords(const std::string& input) {
    std::vector<std::string> words;
    std::string word;
    
    // Traverse the string and split words based on spaces
    for (char ch : input) {
        if (ch == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += ch;
        }
    }
    
    // Add the last word if there is any
    if (!word.empty()) {
        words.push_back(word);
    }

    // Reverse the vector of words
    std::string result;
    for (auto it = words.rbegin(); it != words.rend(); ++it) {
        if (!result.empty()) {
            result += ' ';
        }
        result += *it;
    }

    return result;
}

int main() {
    std::string input = "i am Soumyo";
    std::string output = reverseWords(input);
    
    std::cout << output << std::endl;
    
    return 0;
}
