//
//  Inventory.hpp
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#ifndef Inventory_hpp
#define Inventory_hpp

#include <stdio.h>
#include <vector>
#include "Movie.h"
#include "HashMap.hpp"

class Inventory {
public:
    Inventory();
    void addItem( Movie *);
    std::vector<char> getTypes() { return types; }

private:
    std::vector<char> types;
    HashMap movies;
};

#endif /* Inventory_hpp */
