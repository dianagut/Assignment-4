// ------------------------------------------- ReturnCommand.cpp ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#include "Return.h"

void Return::innerProcess(Movie* m , Customer* c) {
    if (c->doReturn(m)) {
        m->increaseStock(1);
        c->storeHistory(rawCommand);
    }
    else {
        std::cerr << m->getHashKey() << " can't be returned by customer " << c->getID() << " " << c->getName() <<  std::endl;
    }
}
