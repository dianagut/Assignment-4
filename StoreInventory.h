// ------------------------------------------------ Inventory.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will implement StoreInventory
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: Stores movies in inventory
// --------------------------------------------------------------------------------------------------------------------

#ifndef Inventory_hpp
#define Inventory_hpp

#include <stdio.h>
#include <vector>
#include "Movie.h"
#include "HashMap.h"
using namespace std;

class StoreInventory {
    friend ostream& operator<<(ostream& output, const StoreInventory& inv);//overload << operator
public:
    StoreInventory();//constructor
    ~StoreInventory();//destructor
    void addItem(Movie*);//adds movie to inventory
    Movie* findItem(string);//finds movie in inventory

private: 
    void insertSorted(Movie *movie); //insert movie 
    int typeToIndex(char movieType);//checks if movie type is acceptable
    ostream& outSorted(ostream& output) const;
    
    static const int MAX_TYPES = 10;
    // Movies indexed by the HashKey - and that depends on every Movie Type
    HashMap<string, Movie*, MovieHash> movies;
    // optimization to store the sorted list of movies
    // we only store pointers, to avoid wasting memory
    int sortedCount[MAX_TYPES];
    Movie* sorted[MAX_TYPES][100];
    int maxMovieTypes;
};

#endif
