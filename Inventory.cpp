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
#include "Inventory.h"

Inventory::Inventory() {
    for(int i= 0; i < MAX_TYPES; i++) {
        sortedCount[i] = 0;
    }
    maxMovieTypes = 3;
}
void Inventory::addItem(Movie* m) {
    if (m) {
        movies.put(m->getHashKey(), m);
        insertSorted(m);
    }
}

int Inventory::typeToIndex(char movieType) {
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

void Inventory::insertSorted(Movie *movie)
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

 ostream& Inventory::outSorted(ostream& output) const {
    for(int mt = 0 ; mt < maxMovieTypes; mt ++) {
        for(int i = 0; i < sortedCount[mt]; i++) {
            output << *sorted[mt][i] << '\n';
        }
    }
    return output;
}

ostream& operator<<(ostream& output, const Inventory& inv) {
     inv.outSorted(output);
    return output;
}
