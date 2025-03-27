#include <iostream>

/* Read me..
    Why is this an issue?
    - The variable `x` exists only inside getPointer().
    - Once the function exits, `x` is removed from the stack.
    - The returned pointer now refers to invalid memory (stack memory that no longer exists).
    - Dereferencing this pointer results in undefined behavior.

    Best Practices:
    - Never return a pointer to a local variable.
    - Use heap allocation (`new`) if dynamic allocation is needed

*/

// WRONG SOLUTION - will cause UB
int* getPointer() {
    int x = 10;  // Local variable (allocated on the stack)
    return &x;   // ERROR: Returning stack memory (Undefined behavior)
}

// FIXED SOLUTION - since memory is allocated to heap, it will continue to exist outside of this function
// int* getPointer() {
//     return new int(10);
// }

int main() {
    int* ptr = getPointer();  // Function returns a pointer to a local variable
    
    std::cout << "Address: " << ptr << std::endl;
    std::cout << "Accessing memory: " << *ptr << std::endl;  // ERROR

    return 0;
}
