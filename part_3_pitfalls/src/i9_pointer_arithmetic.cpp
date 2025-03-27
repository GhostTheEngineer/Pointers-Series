#include <iostream>

/* Read me..
    Why is this an issue?
    - Pointer arithmetic moves the pointer past the array boundaries.
    - The array `arr[3]` contains only 3 elements (`arr[0]`, `arr[1]`, `arr[2]`).
    - `ptr += 5;` moves the pointer 2 elements beyond the valid range.
    - Accessing this memory results in undefined behavior.

    What happens if we do this?
    - The program may crash if the memory is inaccessible.
    - It may print garbage values if it accesses unallocated memory.
    - Debugging this issue is difficult because the error may not always appear immediately.

    Best Practices:
    - Always ensure pointer arithmetic stays within array bounds:
        if (ptr <= (size - 1)) {  // Safe check
            std::cout << *ptr << std::endl;
        }
    - Use `std::vector<int>` instead of raw arrays to prevent out-of-bounds errors.

*/

int main() {
    const size_t size = 3;

    int arr[size] = {10, 20, 30};  // Array of size 3
    int* ptr = arr;  // Pointer to the first element

    ptr += 5;  // ERROR: Out of bounds (Undefined behavior)
    // CORRECT: ptr += (size - 1); // last element of array

    ptr = arr; // set ptr back to element 1 (10)
    for(int i = 0; i <= 5; ++i) { // ERROR: Out of bounds (Undefined behavior)
    // CORRECT: for(int i = 0; i < (size - 1); ++i) {
        std::cout << "Value: " << *ptr << std::endl; // Undefined behavior once out-of-bounds
        ++ptr; // increment by one - eventually goes out of bounds
    }

    return 0;
}
