/******************************************************************************
 * Project: Smart Pointers for Beginners
 * File: i4_array.cpp
 * Description:
 *   Implements a raw pointer pointing to an array address on the stack memory region.
 *
 * Copyright © 2025 Ghost - Two Byte Tech. All Rights Reserved.
 *
 * This source code is licensed under the MIT License. For more details, see
 * the LICENSE file in the root directory of this project.
 *
 * Version: v1.0.0
 * Author: Ghost
 * Created On: 03-06-2025
 * Last Modified: 03-06-2025
 *****************************************************************************/

#include <iostream>

int main() {
    /* Information..
        The array named "numbers" exists on the stack. Since anything on the stack has a memory address,
        this means the array itself also has an address.

        Arrays are stored in contiguous memory, meaning each element is placed directly next to the other
        in memory. This allows us to access elements sequentially using pointer arithmetic.

        The name of the array "numbers" represents the memory address of its first element. 
        This means we can store that address in a pointer and then increment the pointer to 
        move to the next element.
    */
    int numbers[5] = {10, 20, 30, 40, 50}; // allocated in stack

    int* ptr = numbers;  // Pointer to first element (& not needed)

    std::cout << "First element: " << *ptr << std::endl; // print first element using deference
    ++ptr; // increment the pointer to index 1, value 20
    std::cout << "Second element: " << *ptr << std::endl; // print again to confirm!

    /* Other Examples

        1. Traversing an Array with a Pointer
            - Instead of using an index, a pointer can be incremented to loop through an array.

            Example:
            for (int i = 0; i < 3; i++) {
                std::cout << *ptr << " ";
                ++ptr;
            }

        2. Passing an Array to a Function
            - Since arrays decay into pointers when passed to a function, functions should accept a 
            pointer parameter.

            Example:
            void printArray(int* arr, int size) {
                for (int i = 0; i < size; i++) {
                    std::cout << arr[i] << " ";
                }
            }

            int numbers[3] = {10, 20, 30};
            printArray(numbers, 3); // Function receives a pointer to the first element

        3. Using Pointer Arithmetic to Access Elements
            - Instead of using index notation (arr[i]), you can use *(ptr + i).

            Example:
            for (int i = 0; i < 3; i++) {
                std::cout << *(numbers + i) << " ";  // Equivalent to numbers[i]
            }

        4. Working with Multi-Dimensional Arrays
            - A pointer to an array can be used to access multi-dimensional arrays.

            Example:
            int matrix[2][3] = { {1, 2, 3}, {4, 5, 6} };
            int (*ptr)[3] = matrix;  // Pointer to an array of 3 integers

            std::cout << ptr[0][1];  // Accesses matrix[0][1] (value 2)

        5. Dynamic Arrays and Heap Allocation
            - Unlike stack arrays, heap arrays must be manually allocated and deallocated using new 
            and delete.

            Example:
            int* numbers = new int[3];  // Allocates an array on the heap
            numbers[0] = 10;
            numbers[1] = 20;
            numbers[2] = 30;
            delete[] numbers;  // Free the allocated memory to avoid memory leaks

    */


    return 0;
}
