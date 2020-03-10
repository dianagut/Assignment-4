// ------------------------------------------- ReturnCommand.h ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#ifndef Return_h
#define Return_h

#include "transaction.h"

class Return : public Transaction {
public:
    Return() : Transaction('R') { }
    void processTransaction(StoreInventory*, CustomerStorage*);
    void setData(std::string);

};
#endif
