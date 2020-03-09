//
//  HashMap.hpp
//  Movies
//
//  Created by Francisco Sanchez on 3/7/20.
//  Copyright © 2020 Francisco Sanchez. All rights reserved.
//

#ifndef HashMap_hpp
#define HashMap_hpp

#include <string>
#include "Movie.h"
#include "HashNode.hpp"

// https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
class HashMap {
public:
    HashMap();
    ~HashMap();
    bool get(const std::string &key, Movie* &value);
    void put(const std::string &key,  Movie* value);
    void remove(const std::string &key) ;

private:
    // hash table
    HashNode **table;
    unsigned long hashFunc(const std::string& k) const ;
};
#endif /* HashMap_hpp */
