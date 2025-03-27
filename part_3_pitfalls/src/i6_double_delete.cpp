#include <iostream>

int main() {
    // Allocate memory for an integer on the heap.
    int* ptr = new int(42);  

    std::cout << "Value: " << *ptr << std::endl;  // OUTPUT: 42

    // Free the allocated memory.
    delete ptr;  
    
    // ERROR: Double delete (undefined behavior)
    //delete ptr;  // Attempting to free the same memory again.

    std::cout << "Hello World!\n";

    /* Read me..   
        What happens when calling delete? And if it's called twice on same data?
        - When "delete ptr" is called, the memory is not immediately freed.
        - Instead, it is marked as available for reuse by the system.
        - The memory may still contain old data, but accessing it is unsafe.
        - If "delete ptr" is called again, it tries to free already freed memory, 
          leading to undefined behavior (crash, memory corruption, etc.).

        Best Practice: Always set pointers to nullptr after freeing(delete).
           delete ptr;
           ptr = nullptr;

        If "ptr" is nullptr, calling delete is safe and does nothing.
    */

    return 0;
}
