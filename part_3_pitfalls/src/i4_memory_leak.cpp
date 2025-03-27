#include <iostream>

/* Read me..
    What is a Memory Leak?
    - A memory leak occurs when dynamically allocated memory (`new`) is 
      never deallocated (`delete`).
    - The program keeps running, consuming more memory over time.
    - Since the memory has no pointer referencing it, it cannot be freed.

    Why is this bad?
    - Causes increased memory usage and potential program crashes.
    - Long-running programs (like servers, games) slow down or crash 
      due to excessive memory consumption.
    - The OS does not automatically free heap memory until the program exits.

    Best Practices:
    - Always delete dynamically allocated memory before losing access to it.
    - If making modern software, use smart pointers to avoid mistakes.

*/

void allocateMemory() {
    int* ptr = new int(100);  // Allocating memory on the heap
    // Memory leak: No delete operation, memory is never freed.
    // CORRECT: delete ptr; // ensures no memory leak before leaving function!
}

int main() {
    allocateMemory();  // Function allocates memory but never releases it.
    return 0;
}
