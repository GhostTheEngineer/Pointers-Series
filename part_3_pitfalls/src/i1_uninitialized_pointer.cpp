#include <iostream>

/* Read me..
    What is an Uninitialized Pointer?
    A pointer that is only declared and not set to a memory address or null.
    - A pointer must point to a valid memory location before being used.
    - Declaring a pointer without initializing it means it holds a random(garbage) memory address.
    - Dereferencing such a pointer results in undefined behavior (crashes, memory corruption).

    Why is this dangerous?
    - The pointer may reference random memory, leading to crashes.
    - It may modify critical system memory, causing unpredictable bugs (most likely not due to OS protections).
    - Debugging uninitialized pointer errors is difficult.

    Is it a real memory address?
    Yes, it is technically a memory address—just a random one.
    But it's not guaranteed to be valid, accessible, or even within your program's allocated memory. 
    It could:
    - Be a leftover value from a previous variable that used that memory.
    - Accidentally point to heap, stack, or completely unmapped memory.

    Best Practices:
    - Always initialize pointers before using them.
    - Set pointers to `nullptr` if they don’t point to valid memory(c++11 or later):
        int* ptr = nullptr;
    - If making modern software, use smart pointers to avoid mistakes.

*/


class Vet {
public:
    Vet();
    // ......
};

class Animal {
private:
    Vet* m_Vet; // Uninitialized pointer (Garbage memory address)
    // RECOMMENDED WAY: Vet* m_Vet = nullptr; // C++11 and later ONLY
    int m_Age;
public:
    Animal();
    // ANOTHER WAY: Animal() : m_Vet(NULL) {}; // older c++ versions BUT if you have multiple constructors you must remember to initialize in each one:
    // Animal(int age) : m_Vet(NULL), m_Age(age) {};
    // ............
};


int main() {
    
    int* ptr;  // Uninitialized pointer (Garbage memory address)
    // CORRECT WAY: int* ptr = nullptr; 
    // `nullptr` is a null pointer constant. It's safer than NULL (or 0) in modern C++ (C++11) because it is typed.

    // ERROR: Accessing an uninitialized pointer leads to Undefined Behavior
    std::cout << "Accessing uninitialized pointer: " << *ptr << std::endl;

    return 0;
}
