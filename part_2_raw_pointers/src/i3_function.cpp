/******************************************************************************
 * Project: Smart Pointers for Beginners
 * File: i3_function.cpp
 * Description:
 *   Implements a raw pointer pointing to a function address on the code segment memory region.
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

/* NEW MEMORY REGION: Code Segment (Text Segment)
 *
 * In Part 1, we didn’t discuss this memory region to keep things simple.
 * Now that we are dealing with function pointers, it’s important to understand where functions exist in memory.
 *
 * What is the Code Segment?
 * - It is a special memory region where a program's compiled machine code is stored.
 * - Unlike the stack (which handles function calls) and the heap (which manages dynamic memory), 
 *   the Code Segment holds functions so they can be executed when called.
 *
 * Why does this matter?
 * - When using a pointer to a function, you are storing its memory address.
 * - But where does this memory address come from?
 * 
 * Let's rule out incorrect locations:
 * - Heap? No. The heap is used for dynamically allocated objects (`new`), and it does NOT store functions.
 * - Stack? No. The stack is for temporary function calls (stack frames), but functions themselves are NOT stored here.
 *
 * Correct Answer: Code Segment!
 * - Functions live in the Code Segment (Text Segment), and function pointers hold addresses pointing to this region.
 * - When a function is called, its instructions are fetched from this memory region.
 * - The function’s stack frame (local variables, return addresses) is created on the stack, 
 *   but the actual function remains in the Code Segment.
 *
 * How does function execution work?
 * - When a function is called, the processor jumps to the function’s address in the Code Segment.
 * - The function’s execution starts from this address.
 * - The stack frame stores local variables, return values, and execution state.
 * - Once the function returns, the stack frame is popped, but the function itself always remains in the Code Segment.
 *
 * Key Takeaway:
 * - Function pointers hold addresses of functions stored in the Code Segment.
 * - Functions themselves NEVER exist in the stack or heap.
 * - Function calls push execution state to the stack, but the function remains in the Code Segment.
 */

#include <iostream>

void sayHello() {
    std::cout << "Hello from a function pointer!" << std::endl;
}

// CALL BACK EXAMPLE FUNCTIONS
void greetEnglish() {
    std::cout << "Hello!\n";
}

void greetSpanish() {
    std::cout << "¡Hola!\n";
}

void sayHello(void (*greetFunc)()) {
    std::cout << "Universal Greeting: ";
    greetFunc();  // Calls the function passed as an argument
}


int main() {
    /* Information..
        When declaring a function pointer, you must include the function signature.
        Since the return type is void, that is written first.

        Next, parentheses are wrapped around the identifier for the pointer variable
        "funcPtr" to indicate it is a function pointer. The asterisk (*) before 
        the identifier specifies that it is a pointer.

        Finally, the parameter list is included, just like a regular function declaration.

        Using the assignment operator, you simply assign the function’s name.
        In C++, a function name by itself is already a pointer to its memory address,
        so there is no need to use the ampersand (&) operator.

        Why not use ampersand (&) to explicitly get the function’s address?
        That is because a function’s name is already a pointer. Assigning it to
        another pointer variable simply creates an alias, meaning the function 
        now has two names: "sayHello" and "funcPtr".
    */
    void (*funcPtr)() = sayHello;  // Assign function address to pointer

    funcPtr();  // Call function through pointer
    sayHello(); // Same function call just using its given name(pointer)

    /* Function Pointer Example: Callback Mechanism

        Function pointers allow you to store the address of a function in a variable,
        making it possible to pass functions as arguments to other functions.

        This is useful when you want to execute different functions dynamically 
        without modifying the caller function.

        What does this example do?
        - We define two greeting functions: `greetEnglish` and `greetSpanish`.
        - The `sayHello` function takes a function pointer as an argument.
        - This allows us to pass different greeting functions dynamically.
        - Instead of calling functions directly, we use a function pointer.

        Why use function pointers here?
        - The `sayHello` function does not need to know which greeting to use.
        - The function pointer allows us to change behavior dynamically.
        - This is similar to how event handlers work in real applications.
    */
    void (*greetPtr)() = greetEnglish; // declare pointer and set to english first
    sayHello(greetPtr);  // Call this function, pass function pointer and it will handle calling correct function

    greetPtr = greetSpanish; // update to spanish
    sayHello(greetPtr); 

    return 0;
}
