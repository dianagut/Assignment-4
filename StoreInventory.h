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

class StoreInventory {
    friend ostream& operator<<(ostream& output, const StoreInventory& inv);
public:
    StoreInventory();
    ~StoreInventory();
    void addItem(Movie*);
    Movie* findItem(std::string);

private: 
    void insertSorted(Movie *movie);
    int typeToIndex(char movieType);
    ostream& outSorted(ostream& output) const;
    
    static const int MAX_TYPES = 10;
    // Movies indexed by the HashKey - and that depends on every Movie Type
    HashMap<std::string, Movie*, MovieHash> movies;
    // optimization to store the sorted list of movies
    // we only store pointers, to avoid wasting memory
    int sortedCount[MAX_TYPES];
    Movie* sorted[MAX_TYPES][100];
    int maxMovieTypes;
};

#endif
