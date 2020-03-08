//
//  main.cpp
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Movie.h"
#include <vector>
#include "Inventory.hpp"

int main(int argc, const char * argv[]) {
    std::ifstream infile("data4movies.txt");
    std::string line;
    Inventory inv;
    
    while (std::getline(infile, line))
    {
        Movie *m = Movie::fromLine(line);
        if (m) {
            inv.addItem(m);
        }
    }
    
   
}
