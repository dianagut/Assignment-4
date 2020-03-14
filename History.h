// ------------------------------------------- HistoryCommand.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This file creates the transaction class
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: file will be formatted correctly
// --------------------------------------------------------------------------------------------------------------------

#ifndef History_h
#define History_h

#include "transaction.h"

class History : public Transaction 
{
public:
    //history H
    History() : Transaction('H') { }
    //processes transaction
    void processTransaction(StoreInventory*, CustomerStorage*);
    //sets the data
    void setData(string);
};
#endif
