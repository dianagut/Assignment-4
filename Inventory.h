// ------------------------------------------- InventoryCommand.h ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This file creates the inventory class. the child class of transaction
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: File will be formatted correctly
// --------------------------------------------------------------------------------------------------------------------

#ifndef Inventory_h
#define Inventory_h

#include "transaction.h"

class Inventory : public Transaction {
public:
    //inventory type I
    Inventory() : Transaction('I') { }
    //processes transaction
    void processTransaction(StoreInventory*, CustomerStorage*);

};
#endif
