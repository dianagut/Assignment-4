// ------------------------------------------------ Inventory.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#ifndef Inventory_hpp
#define Inventory_hpp

#include <stdio.h>
#include <vector>
#include "Movie.h"
#include "HashMap.h"

class Inventory {
    friend ostream& operator<<(ostream& output, const Inventory& inv);
public:
    Inventory();
    void addItem(Movie*);
    std::vector<char> getTypes() { return types; }

private:
    void insertSorted(Movie *movie);
    int typeToIndex(char movieType);
    ostream& outSorted(ostream& output) const;
    
    static const int MAX_TYPES = 10;
    std::vector<char> types;
    HashMap movies;
    int sortedCount[MAX_TYPES];
    Movie* sorted[MAX_TYPES][100];
    int maxMovieTypes;
};

#endif
