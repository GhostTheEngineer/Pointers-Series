/******************************************************************************
 * Project: Smart Pointers for Beginners
 * File: i2_heap.cpp
 * Description:
 *   Implements a raw pointer pointing to an address on the heap memory region.
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

// STEP 3 - see STEP 2 first.
void myFunc() {
    int* ptr = new int(50); // allocate memory on heap, "ptr" is placed in this function temp stack(frame)
    // Do stuff, maybe loop for a while
    delete ptr; // free memory or it will be lost on heap with no access since "ptr" is popped from this temp stack(frame)
}

int main() {
    /* STEP 1: Allocation
        When allocating to heap, you must use the "new" keyword operator, placed before the type 
        you wish to allocate.
        
        Below we allocate an integer to the heap with a value of 50. The new keyword, once allocation 
        is complete, will return the memory address which we store in our pointer variable "ptr". 
    */
    int* ptr = new int(50);  // Allocated on heap, pointer "ptr" goes on stack

    std::cout << "Heap Value: " << *ptr << std::endl;

    // STEP 3 - see STEP 2 first.
    myFunc();

    /* STEP 2: Deallocation
        Using the "delete" keyword operator, we can free the memory in which "ptr" is pointing to. 
        
        NOTE: Since we are at the end of the program, freeing the memory was not necessary 
        because all memory will be freed by the operating system. BUT in other cases, 
        like in STEP 3, you should free the memory.
    */
    delete ptr;  // Free memory to avoid leaks

    return 0;
}
