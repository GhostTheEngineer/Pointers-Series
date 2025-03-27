#include <iostream>

/* Read me..
    Why is deleting a stack pointer dangerous?
    - Stack memory is automatically managed by the program.
    - Variables like `x` and `ptr` are allocated on the stack and will be 
      automatically freed when the function exits.
    - Using `delete` on a pointer to stack memory causes undefined behavior.

    What happens if we do this?
    - Since `delete` is meant for heap-allocated memory (`new`), 
      calling `delete` on stack memory may corrupt the stack.
    - This can cause a crash or unexpected behavior.

    Best Practices:
    - Never use `delete` on a pointer to stack memory.
    - Use `delete` only for heap-allocated memory (memory allocated with `new`).
    - If making modern software, use smart pointers to avoid mistakes.

*/

int main() {
    int x = 10;
    int* ptr = &x;  // Pointer to a stack variable

    delete ptr;  // ERROR: Deleting a stack-allocated variable (undefined behavior)

    return 0;
}
