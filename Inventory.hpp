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
    friend std::ostream & operator<<(std::ostream &, const Inventory &);
public:
    Inventory();
    void addItem( Movie *);
    std::vector<char> getTypes() { return types; }

private:
    static const int MAX_TYPES = 10;
    int typeToIndex(char );
    std::vector<char> types;
    HashMap movies;
    Movie* sorted[MAX_TYPES][100];
    int sortedCount[MAX_TYPES];
    int maxMovieTypes = 3;
    void insertSorted(Movie *m);
    ostream& outSorted(ostream& output) const;
};

#endif /* Inventory_hpp */
