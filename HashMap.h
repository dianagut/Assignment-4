// ------------------------------------------------HashMap.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// -------------------------------------------------------------------------------------------------------------------- // Notes on specifications, special algorithms, and assumptions. 
// -------------------------------------------------------------------------------------------------------------------- 

#ifndef HashMap_hpp
#define HashMap_hpp

#include <string>
#include "Movie.h"
#include "HashNode.h"

// https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
class HashMap {
public:
    HashMap();
    ~HashMap();
    bool get(const std::string& key, Movie*& value);
    void put(const std::string& key, Movie* value);
    void remove(const std::string& key);

private:
    // hash table
    HashNode** table;
    unsigned long hashFunc(const std::string& k) const {
        return k.length() % TABLE_SIZE;
    }
};
#endif 
