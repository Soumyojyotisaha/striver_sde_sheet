#include <iostream>
#include <stdexcept> // For std::runtime_error
using namespace std;

// Object-Oriented Programming (OOP) vs. Procedural-Oriented Programming (POP)
// OOP follows a bottom-up approach and focuses on objects and classes.
// POP follows a top-down approach and focuses on functions.

// Class Definition
class Car {
    int price, color;
public:
    void braking() {}
    void accelerate() {}
};

// Creating an object of the class
Car audi;

// Pillars of OOP:
// E: Encapsulation
// P: Polymorphism
// I: Inheritance
// D: Data Abstraction

// Polymorphism:
// 1. Compile-time -> Function overloading
// 2. Run-time -> Function overriding

// Function Overloading
int area(int a) {
    return a * a;
}

int area(int a, int b) {
    return a * b;
}

// Main for function overloading
int main() {
    int b = area(4);
    int c = area(2, 3);
    cout << b << " " << c << endl;
    return 0;
}

// Function Overriding
class A {
public:
    virtual int area() {
        // Implementation can be provided here
        return 0;
    }
};

class B : public A {
public:
    int area() override {
        // Overridden implementation
        return 0;
    }
};

// Main for function overriding
int main() {
    B ob;
    ob.area(); // Derived class method called
    return 0;
}

// Static Variable
class A {
public:
    int x;
    static int y; // Static variable declaration
};

// Static variable definition outside the class
int A::y = 0;

A ob1, ob2; // Single copy of y made for both ob1 and ob2

// Friend Function
class Box {
private:
    int length;
public:
    Box() : length(0) {} // Constructor with initialization list

    // Friend function declaration
    friend int printLength(Box);
};

// Friend function definition
int printLength(Box b) {
    b.length += 10;
    return b.length;
}

// Main for friend function
int main() {
    Box b;
    cout << "Length of box: " << printLength(b) << endl;
    return 0;
}

// Call by Value and Call by Reference
void fun1(int a) {
    a = 20;
}

void fun2(int &a) { // Receives address
    a = 20;
}

// Main for call by value and reference
int main() {
    int a = 40;
    fun1(a);
    cout << a << " "; // Call by value does not modify the original value

    fun2(a);
    cout << a << endl; // Call by reference modifies the original value
    return 0;
}

// Constructor and Destructor
class Z {
public:
    Z() {
        cout << "Constructor called" << endl;
    }
    Z(int x) {
        // Parameterized constructor
    }
    ~Z() {
        cout << "Destructor called" << endl;
    }
};

// Main for constructor and destructor
int main() {
    Z ob;
    Z ob1(2);
    return 0;
}

// References and Pointers
int main() {
    // Reference
    int x = 20;
    int &ref = x; // 'ref' is a reference to 'x'
    ref = 91;     // Modifying 'ref' will modify 'x'
    cout << "Value of x: " << x << endl; // Output will be 91

    // Pointer
    int a = 2;
    int *p = &a; // 'p' is a pointer to 'a'
    cout << "Address of a: " << p << endl; // Output will be the memory address of 'a'
    cout << "Value at address p: " << *p << endl; // Output will be 2

    return 0;
}

// Reference vs Pointer
int a = 10;
void* aa = &a; // Valid
// void &ar = a; // Invalid

// Pointers can have multi-level indirection: single, double, triple
// References can have only a single level of indirection

// Virtual Function
class Base {
public:
    virtual void print() {
        cout << "Base class print function" << endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        cout << "Derived class print function" << endl;
    }
};

// Main for virtual function
int main() {
    Derived derived;        // Create an object of Derived
    Base* base = &derived;  // Pointer of type Base pointing to Derived object

    base->print();          // Calls Derived class's print function due to virtual function

    return 0;
}

// Type Conversion: Implicit and Explicit
// Implicit Conversion
int main() {
    int num1 = 25;   // Integer
    float num2;      // Floating-point

    num2 = num1;     // Implicit conversion: int to float

    cout << "num1: " << num1 << endl;   // Output: 25
    cout << "num2: " << num2 << endl;   // Output: 25.0

    return 0;
}

// Explicit Conversion
int main() {
    float num1 = 25.75;  // Floating-point
    int num2;

    num2 = static_cast<int>(num1);    // C++ style cast: float to int

    cout << "num1: " << num1 << endl; // Output: 25.75
    cout << "num2: " << num2 << endl; // Output: 25

    return 0;
}

// Default Parameters
int sum(int x, int y, int z = 0, int w = 0) {
    return (x + y + z + w);
}

// Main for default parameters
int main() {
    cout << sum(10, 15) << endl;       // Output: 25 (10 + 15 + 0 + 0)
    cout << sum(10, 15, 25) << endl;   // Output: 50 (10 + 15 + 25 + 0)
    cout << sum(10, 15, 20, 25) << endl; // Output: 70 (10 + 15 + 20 + 25)
    return 0;
}

// Inline Function
inline int cube(int s) {
    return s * s * s;
}

// Main for inline function
int main() {
    cout << cube(2) << endl; // Output will be 8
    return 0;
}

// Macros
#define LIMIT 5
#define AREA(l, b) ((l) * (b))

void printNumbers() {
    // Function to print numbers from 0 to LIMIT-1
    for (int i = 0; i < LIMIT; i++) {
        cout << i << "\n";
    }
}

void calculateArea() {
    // Function to calculate area using macro AREA
    int l1 = 10, l2 = 12;
    int area = AREA(l1, l2);
    cout << "Area: " << area << endl;
}

// Main for macros
int main() {
    printNumbers();   // Call function to print numbers
    calculateArea();  // Call function to calculate and print area
    return 0;
}

// Exception Handling with a resource management class
class Resource {
public:
    Resource() {
        cout << "Resource acquired" << endl;
    }

    ~Resource() {
        // Destructor to simulate cleanup
        cout << "Resource released" << endl;
    }

    void process(int value) {
        if (value < 0) {
            throw runtime_error("Value must be non-negative");
        }
        cout << "Processing value: " << value << endl;
    }
};

// Main for exception handling
int main() {
    try {
        Resource res; // Resource acquisition

        // Code that might throw an exception
        res.process(-1); // This will throw an exception

    } catch (const runtime_error& e) {
        // Handle exceptions of type runtime_error
        cout << "Caught exception: " << e.what() << endl;
    } catch (...) {
        // Handle any other type of exception
        cout << "Caught an unknown exception" << endl;
    }

    // After leaving the try block, the destructor of Resource will be called
    // This acts like a 'finally' block in other languages, ensuring cleanup.

    return 0;
}

// Copy Constructor
class Teacher {
private:
    double salary;

public:
    string name;
    string subject;
    string dept;

    // Default constructor
    Teacher() : dept("cse") {}

    // Parameterized constructor
    Teacher(string name, string subject, string dept) : name(name), subject(subject), dept(dept) {}

    // Copy constructor
    Teacher(const Teacher &other) : name(other.name), subject(other.subject), dept(other.dept) {}

    // Method to display teacher details
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Subject: " << subject << endl;
        cout << "Department: " << dept << endl;
    }
};

// Main for copy constructor
int main() {
    Teacher teacher1; // Uses default constructor
    Teacher teacher2("John Doe", "Mathematics", "Physics"); // Uses parameterized constructor

    // Displaying information of teachers
    cout << "Teacher 1:" << endl;
    teacher1.display();
    cout << endl;

    cout << "Teacher 2:" << endl;
    teacher2.display();
    cout << endl;

    // Creating a copy of teacher2 using the copy constructor
    Teacher t3(teacher2);
    cout << "Teacher 3 (Copy of Teacher 2):" << endl;
    t3.display();

    return 0;
}

// Abstract Class
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override { // Override pure virtual function
        cout << "Circle" << endl;
    }
};

// Main for abstract class
int main() {
    Circle c1;
    c1.draw(); // Output: Circle
    return 0;
}
