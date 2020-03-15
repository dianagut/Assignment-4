// ------------------------------------------------ Inventory.cpp -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Stores and sorts movies in inventory
// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include "StoreInventory.h"
using namespace std;

// ---------------------constructor--------------------------------
// constructor: creates store inventory
// preconditions: New storeInventtory object is created
// -------------------------------------------------------------------------
StoreInventory::StoreInventory() {
    for(int mt= 0; mt < MAX_TYPES; mt++) { //loop to initialize array
        sortedCount[mt] = 0; // set all elements to 0
        for(int i = 0; i < sortedCount[mt]; i++) {
            sorted[mt][i] = NULL; //set all elements to NULL
        }
    }
    maxMovieTypes = 3; //only F,D, or C
}

// ---------------------destructor--------------------------------
// destructor: frees all memory allocated
// preconditions: Memory is allocated
// postconditions: Memory will be freed
// -------------------------------------------------------------------------
StoreInventory::~StoreInventory() {
    for(int mt= 0; mt < MAX_TYPES; mt++) { // loop to go through array
        for(int i = 0; i < sortedCount[mt]; i++) {
            if (sorted[mt][i]) {
                delete sorted[mt][i]; // deletes all elements in array
            }
        }
    }
}

// ---------------------addItem--------------------------------
// addItem: adds movie to hashmap
// preconditions: Must have a movie object
// postconditions: will add movie to hashmap
// -------------------------------------------------------------------------
void StoreInventory::addItem(Movie* movie) {
    if (movie) { // if there is an accurate movie object
        movies.insert(movie->getHashKey(), movie); // put in hashtable
        insertSorted(movie); // call insertSorted method
    }
}

// ---------------------findItem--------------------------------
// findItem: finds a movie using key
// preconditions: must have movie key
// -------------------------------------------------------------------------
Movie* StoreInventory::findItem(string key) {
    Movie *m = NULL; // create a pointer
    movies.retrieve(key, m); // check if movie exists in inventory
    return m;
}

// ---------------------typeToIndex--------------------------------
// typeToIndex: checks if movie type is acceptable
// preconditions: Takes in movie type
// postconditions: Returns 0 for F, 1 for D, 2 for C and -1 otherwise
// -------------------------------------------------------------------------
int StoreInventory::typeToIndex(char movieType) {
    switch(movieType) {
        case 'F':
            return 0;
        case 'D':
            return 1;
        case 'C':
            return 2;
        default:
            cerr << "Error " << movieType << " is not supported";//print if movie type is not recognized
    }
    return -1;
}

// ---------------------insertSorted--------------------------------
// insertSorted: inserts movie in inventory
// preconditions: Movie object must exist
// postconditions: inserts movie
// -------------------------------------------------------------------------
void StoreInventory::insertSorted(Movie *movie)
{
    int bucket = typeToIndex(movie->getMovieType()); // movie type
    if (bucket >= 0) { // if movie type is recognized
        int place = 0;
        while((place < sortedCount[bucket] ) && *sorted[bucket][place] <  *movie ) {
            place++; // insert in inventory / hashmap
        }
        if (place < sortedCount[bucket]) {
            for(int i = sortedCount[bucket]; i > place; i--) {
                sorted[bucket][i] = sorted[bucket][i-1]; // insert in inventory/ hashmap
            }
        }
        sortedCount[bucket]++;
        sorted[bucket][place] = movie;
    }
}

// ---------------------outSorted--------------------------------
// outSorted: output movies
// postconditions: outputs sotrted movies to console
// -------------------------------------------------------------------------
 ostream& StoreInventory::outSorted(ostream& output) const {
    for(int mt = 0 ; mt < maxMovieTypes; mt ++) { //loop through array
        for(int i = 0; i < sortedCount[mt]; i++) {
            output << *sorted[mt][i] << endl ;//print out every element
        }
    }
    return output;
}

// ---------------------operator << overload--------------------------------
// operator<<: outputs  to console
// -------------------------------------------------------------------------
ostream& operator<<(ostream& output, const StoreInventory& inv) {
     inv.outSorted(output);
    return output;
}
