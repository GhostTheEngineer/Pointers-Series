/******************************************************************************
 * Project: Smart Pointers for Beginners
 * File: i5_npc_example.cpp
 * Description:
 *   An example implementing pointers for stack, heap, function and array themed around an npc character.
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

/* Information..

    The following examples demonstrate different types of pointers, including 
    stack, heap, function, and array pointers. 

    These examples are intended for learning purposes only and are not necessarily 
    the best approach or a recommended way to use pointers in practical applications.

*/

// Character Class
class Character {
private:
    std::string name;
    int level;
public:
    Character(std::string name) : name(name), level(1) {
        std::cout << "[System] " << name << " has entered the game!\n";
    }
    ~Character() {
        std::cout << "[System] "  << name << " has left the game.\n";
    }

    // Methods
    void attack() {
        std::cout << " --> " << name << " attacks the enemy!\n";
    }

    void increaseLevel(int levelCoin) {
        level += levelCoin;
    }

    // Getters
    int getLevel() const {
        return level;
    }

    std::string getName() const {
        return name;
    }
};


// Function to be used with a function pointer
void levelUp(Character* _char, int* coin) {
    std::cout  << "[LEVEL COIN] "  << _char->getName() << " is leveling up! Current: " << _char->getLevel() << "..";
    
    _char->increaseLevel(*coin); // calls to increase a characters level
    
    std::cout << " new level: " << _char->getLevel() << "\n";
}


int main() {
    // 1) STACK POINTER (Pointer to a local variable)
    int levelCoin = 5;  // Stored on the stack
    int* levelPtr = &levelCoin;  // Stack pointer
    std::cout << "[System] "  << "Level Coin Created: " << *levelPtr << std::endl;  // Dereferencing

    // 2) HEAP POINTER (Dynamically allocated object)
    Character* hero = new Character("Warrior"); // Allocate object on the heap
    /* Arrow Operator
        The arrow operator (->) is used to access a member function or variable of 
        an object through a pointer. Since "hero" is a pointer to a Character object, 
        "hero->attack();" calls the "attack" function on the object it points to.

        This is equivalent to using (*hero).attack(); but the arrow operator provides 
        a cleaner and more readable way to access members of a pointer to an object.

        Remember, pointers are not references and require derefencing - arrow operators
        do so in a clean way to access members of a class.
    */
    hero->attack();

    // 3) FUNCTION POINTER (Pointer to a function)
    void (*levelTrigger)(Character*, int*) = levelUp; // Assign function pointer
    levelTrigger(hero, levelPtr);  // Call function via pointer

    // 4) ARRAY POINTER(Heap) (Pointer to an array of Characters)
    Character* party = new Character[2] { {"Mage"}, {"Archer"} };

    std::cout << "[System] " << "Party Members:\n";
    for (int i = 0; i < 2; i++) {
        // Accessing array through pointer using arithmetic
        // (*(party + i)).attack(); // this way works as well since you dereference but it looks messy
        (party + i)->attack();  // cleaner way to dereference using arrow operator
        *levelPtr = 2; // modify the level coin value using dereference
        levelTrigger((party + i), levelPtr); // call levelUp function using the pointer we created
    }

    // 5) Clean up memory to prevent leaks (not necessary since we are at end of program but for demonstration)
    delete hero;        // Free dynamically allocated single object
    delete[] party;     // Free dynamically allocated array - since array, use [] with delete!

    return 0;
}
