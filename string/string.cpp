#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str); // Read a full line of input into str
    cout << "You entered: " << str << endl;
    return 0;
}