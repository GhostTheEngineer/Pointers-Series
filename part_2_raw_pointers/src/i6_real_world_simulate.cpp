/******************************************************************************
 * Project: Smart Pointers for Beginners
 * File: i6_real_world_example.cpp
 * Description:
 *   Implements a raw pointer real example when low level programming with hardware registers.
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

/* Information..
    This example is a simulation of a real world example for when a raw pointer should be used.

    When writing device drivers, firmware, or interacting with embedded systems, raw pointers 
    are the only option because we need direct access to hardware registers. Smart pointers 
    cannot be used here because:
        - Hardware registers do not follow RAII (you don’t "own" memory to manage).
        - Memory addresses are fixed (you must use raw pointers to access them).
        - Low-level systems cannot afford extra overhead from smart pointer safety mechanisms.

    This example accesses a hardware register to flip bit for an LED light. 
*/

#include <iostream>
#include <cstdint>  // For fixed-width integer types
#include <thread>  // For sleep
#include <chrono>  // For timing

// Simulating a hardware register (instead of a real memory-mapped address)
uint32_t fakeRegister = 0; 

void setConsoleColor(bool ledOn) { // Cross platform
    #ifdef _WIN32 // Windows
        if (ledOn) system("color E");  // Yellow text
        else system("color 7");        // White text
    #else // MAc/Linux
        if (ledOn) std::cout << "\033[33m";  // Yellow text
        else std::cout << "\033[0m";         // Reset to default
    #endif
}

void displayLED(volatile uint32_t* reg) {
    std::cout << ((*reg & 0x01) ? "💡 LED ON\n" : "❌ LED OFF\n");
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate time delay
}

void updateLED(volatile uint32_t* reg, uint32_t v) {
    *reg = v; // Writing to the memory-mapped register
    setConsoleColor(*reg & 0x01);  // Change text color based on LED state
    displayLED(reg);
}


int main() {
    /* Why Use `volatile` for Hardware Registers?
       The volatile keyword tells the compiler that a variable's value might change unexpectedly, 
       without being directly modified by the program's code. This is crucial when dealing with hardware 
       registers, shared data between threads, or interrupt handlers. 
     
       Even though `volatile` was deprecated for regular variables in C++20, 
       it is still necessary for embedded systems and low-level programming.

       If you don't use it, the compiler may optimize and throw away some read/writes which is NOT
       what we want so we label as `volatile` to ensure the compiler does not optimize it!
    */
    volatile uint32_t* regPtr = &fakeRegister; // Raw pointer to access a hardware memory-mapped register

    displayLED(regPtr); // show initial led state
    
    updateLED(regPtr, 0x01); // on - 0x01 is hexidecimal, 01 = 1. 0x prefix indicates the number is in hexadecimal format.
    updateLED(regPtr, 0); // off

    return 0;
}
