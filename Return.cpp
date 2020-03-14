// ------------------------------------------- ReturnCommand.cpp ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Inner proccess of the return transaction
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: Will process updates that need to happen when a return is made
// --------------------------------------------------------------------------------------------------------------------

#include "Return.h"
using namespace std;

// ---------------------innerProcess--------------------------------
// innerProcess: will call functions to do necessary updates when a return is made
// preconditions: A valid return is made
// postconditions: updates stock and history
// -------------------------------------------------------------------------
void Return::innerProcess(Movie* m , Customer* c) {
    if (c->doReturn(m)) { // if valid return
        m->increaseStock(1); //update stock
        c->storeHistory(rawCommand); // update history
    }
    else {
        cerr << m->getHashKey() << " can't be returned by customer " << c->getID() <<  endl; // print if not a valid return
    }
}
