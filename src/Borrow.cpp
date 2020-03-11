// ------------------------------------------------BorrowCommand.cpp----------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------


#include <vector>
#include <iterator>
#include <algorithm>
#include "Borrow.h"


void Borrow::innerProcess(Movie* m, Customer* c) {
    if (!m->descreaseStock(1)) {
        std::cerr << "Not enough of " << movieData << std::endl;
    } else {
        c->storeHistory(rawCommand);
        c->doBorrow(m);
    }
}
