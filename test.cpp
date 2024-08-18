#include <iostream>
using namespace std;

// Abstract class with a pure virtual function
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

// Derived class implementing the pure virtual function
class Circle : public Shape {
public:
    void draw() override { // Override pure virtual function
        cout << "Circle" << endl;
    }
};

int main() {
    Circle c1;
    c1.draw(); // Output: Circle
    return 0;
}
