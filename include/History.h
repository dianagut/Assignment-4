// ------------------------------------------- HistoryCommand.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#ifndef History_h
#define History_h

#include "transaction.h"

class History : public Transaction {
public:
    History() : Transaction('H') { }
    void processTransaction(StoreInventory*, CustomerStorage*);
    void setData(std::string);
};
#endif
