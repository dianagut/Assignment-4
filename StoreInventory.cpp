// ------------------------------------------------ Inventory.cpp -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include "StoreInventory.h"

StoreInventory::StoreInventory() {
    for(int mt= 0; mt < MAX_TYPES; mt++) {
        sortedCount[mt] = 0;
        for(int i = 0; i < sortedCount[mt]; i++) {
            sorted[mt][i] = NULL;
        }
    }
    maxMovieTypes = 3;
}

StoreInventory::~StoreInventory() {
    for(int mt= 0; mt < MAX_TYPES; mt++) {
        for(int i = 0; i < sortedCount[mt]; i++) {
            if (sorted[mt][i]) {
                delete sorted[mt][i];
            }
        }
    }
}

void StoreInventory::addItem(Movie* m) {
    if (m) {
        movies.put(m->getHashKey(), m);
        insertSorted(m);
    }
}

int StoreInventory::typeToIndex(char movieType) {
    switch(movieType) {
        case 'C':
            return 0;
        case 'D':
            return 1;
        case 'F':
            return 2;
        default:
            std::cout << "Error " << movieType << " is not supported";
    }
    return -1;
}

void StoreInventory::insertSorted(Movie *movie)
{
    int bucket = typeToIndex(movie->getMovieType());
    if (bucket >= 0) {
        int place = 0;
        while((place < sortedCount[bucket] ) && *sorted[bucket][place] <  *movie ) {
            place++;
        }
        if (place < sortedCount[bucket]) {
            for(int i = sortedCount[bucket]; i > place; i--) {
                sorted[bucket][i] = sorted[bucket][i-1];
            }
        }
        sortedCount[bucket]++;
        sorted[bucket][place] = movie;
    }
}

 ostream& StoreInventory::outSorted(ostream& output) const {
    for(int mt = 0 ; mt < maxMovieTypes; mt ++) {
        for(int i = 0; i < sortedCount[mt]; i++) {
            output << *sorted[mt][i] << '\n';
        }
    }
    return output;
}

ostream& operator<<(ostream& output, const StoreInventory& inv) {
     inv.outSorted(output);
    return output;
}
