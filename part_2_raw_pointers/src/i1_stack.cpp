/******************************************************************************
 * Project: Smart Pointers for Beginners
 * File: i1_stack.cpp
 * Description:
 *   Implements a raw pointer pointing to an address on the stack memory region.
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
    int x = 42;  // Stored on the stack

    /* Pointer for Stack Address (Breakdown)

        A pointer is created using the asterisk (*) operator. This operator is placed after 
        the type to indicate that the variable being declared is a pointer, not a regular variable. 

        Since "x" is an integer variable stored on the stack, we need a pointer of the same type 
        to hold its memory address. This is done by declaring an integer pointer using "int*". 
        The asterisk signifies that the variable is a pointer to an integer, not an integer itself. 

        The pointer variable, in this case "ptr", is assigned the memory address of "x". To obtain 
        this address, we use the ampersand (&) operator. This operator is known as the "address of" 
        operator and is a core part of the C++ language. It retrieves the memory address of a 
        variable when placed before its name.

        Since "x" is stored on the stack, its address is retrieved and stored in "ptr", allowing 
        access to "x" indirectly through the pointer. The pointer now holds a reference to 
        stack memory rather than an actual value.
    */

    int* ptr = &x;  // Pointer to stack variable (NOTE: pointer is also on the stack)

    /* What's on the stack?

        At this point, the following (from top to bottom):
            ptr(int*) = 0x1b42... 
            x(int) = 42
    
    */

    std::cout << "Memory address: " << ptr << std::endl; // this will display the memory address of "x" being held by "ptr"

    /* How to Access the Data a Pointer is Pointing To

        To access the value stored at the memory address a pointer holds, use the asterisk (*) 
        before the pointer's name. This is called dereferencing and allows the pointer to act 
        as if it were the original variable.

        If "ptr" holds the address of "x", then "*ptr" retrieves or modifies the data stored 
        at that memory location.
    */
    std::cout << "Value(via ptr variable): " << *ptr << std::endl; // this will display the value at the pointer

    /* How to "Modifying data using pointer.."
    
        Using the dereference operator asterisk(*) again, we gain access to the data using the address assigned
        to the pointer variable "ptr" so we can now just assign it to something else!

    */
    *ptr = 100; 
    
    std::cout << "Modified Value(via x variable): " << x << std::endl; // prove that the pointer is pointing to the memory of "x"

    /* NEVER use "delete" with a pointer pointing to stack memory!

        The "delete" keyword should only be used with heap-allocated memory, not stack memory.

        If a pointer holds the address of a stack variable, attempting to use "delete" on it 
        will result in undefined behavior. This can lead to program crashes, memory corruption, 
        or unpredictable behavior.

        Stack memory is automatically managed, so it does not need to be manually freed.
    */
    // delete ptr; // ERROR 

    return 0;
}
 