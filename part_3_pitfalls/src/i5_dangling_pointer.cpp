#include <iostream>

/* Read me..
    What is a Dangling Pointer?
    - A dangling pointer is a pointer that still holds the address of 
      memory that has already been freed.
    - Even though `ptr` still has a memory address, that memory no longer 
      belongs to our program.
    - Accessing or modifying a dangling pointer leads to undefined behavior.

    Why is this dangerous?
    - The program may seem to work fine, but it can crash unpredictably.
    - The memory may be reallocated for something else, causing data corruption.

    Best Practices:
    - Always set pointers to `nullptr` after deleting:
        delete ptr;
        ptr = nullptr;
    - If making modern software, use smart pointers to avoid mistakes.

*/


int main() {
    int* ptr = new int(42);  // Allocate memory on the heap
    delete ptr;  // Memory is freed
    
    // CORRECT: ptr = nullptr; // Set pointer variable to null so it is not "dangling"

    // Attempting to use after delete - ERROR: Dangling pointer (Undefined behavior)
    std::cout << "Using dangling pointer: " << *ptr << std::endl;

    return 0;
}
