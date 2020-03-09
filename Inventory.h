
// ------------------------------------------------ Inventory.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// -------------------------------------------------------------------------------------------------------------------- // Notes on specifications, special algorithms, and assumptions. 
// -------------------------------------------------------------------------------------------------------------------- 

#ifndef Inventory_hpp
#define Inventory_hpp

#include <stdio.h>
#include <vector>
#include "Movie.h"
#include "HashMap.h"

class Inventory {
public:
    Inventory();
    void addItem(Movie*);
    std::vector<char> getTypes() { return types; }

private:
    std::vector<char> types;
    HashMap movies;
};

#endif 
