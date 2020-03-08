//
//  Inventory.cpp
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//


#include "Inventory.hpp"

Inventory::Inventory() {
    
}
void Inventory::addItem( Movie *m) {
    if (m) {
        movies.put(m->getTitle(), m);
    }
}
