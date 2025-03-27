#include <iostream>

/* Read me..
    Why is this an issue?
    - When allocating a single object, use `new` and `delete`.
    - When allocating an array, use `new` and `delete[]`.
    - `delete` only calls the destructor for a single object.
    - `delete[]` ensures all elements in an array are properly deleted.

    What happens if we use `delete` instead of `delete[]`?
    - Only the first element in the array might be freed.
    - The remaining elements may remain in memory, causing a memory leak.
    - This is undefined behavior, it might work sometimes, but fail unpredictably.

    Best Practices:
    - Always use `delete[]` when dealing with arrays:
        delete[] arr;
    - Prefer `std::vector<int>` instead of raw dynamic arrays.

*/

int main() {
    int* arr = new int[5];  // Allocate an array on the heap

    delete arr;  // ERROR: Undefined behavior
    // CORRECT: delete[] arr;

    return 0;
}
