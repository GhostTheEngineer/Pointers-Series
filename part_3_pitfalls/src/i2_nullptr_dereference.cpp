#include <iostream>

int main() {
    
    int* ptr = nullptr; // nullptr is C++11 or later

    // Dereferencing a null pointer results in undefined behavior:
    std::cout << "Value at pointer: " << *ptr << std::endl;  // ERROR: Undefined behavior 
    // **NOTE** - due to Architectures and/or compiler, your program may not crash and printing will still happen. 
    // BUT it is still considered UB(Undefined behavior) and should be avoided!

    // Example of correct way to deal with this:
    // Always check if a pointer is nullptr before dereferencing.
    if (ptr) { // implicitly converts "ptr" to boolean, so nullptr(0) is false, any value higher than 0 is true
        /* Read me..
            Since pointers hold memory addresses (which are essentially 
            just integers), the condition implicitly converts to boolean.
            - A non-zero memory address is considered 'true'.
            - A null (zero) memory address is considered 'false'.
            This shorthand way of checking pointers is commonly used in C++.
        */
        std::cout << "Value at pointer: " << *ptr << std::endl;
    }
    else {
        std::cout << "\"ptr\" is \'nullptr\'!" << std::endl;
    }

    return 0;
}
