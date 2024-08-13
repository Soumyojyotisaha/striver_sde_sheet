#include <iostream>

class Base {
public:
    // Virtual function to allow overriding
    virtual void show() {
        std::cout << "Base class show function" << std::endl;
    }
};

class Derived : public Base {
public:
    // Overriding the base class function
    void show(){
        std::cout << "Derived class show function" << std::endl;
    }
};

int main() {
    Base* basePtr;
    Derived derivedObj;

    basePtr = &derivedObj;

    // Calls the overridden function in the Derived class
    basePtr->show();

    return 0;
}
