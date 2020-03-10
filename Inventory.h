// ------------------------------------------- InventoryCommand.h ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#ifndef Inventory_h
#define Inventory_h

#include "transaction.h"

class Inventory : public Transaction {
public:
    Inventory() : Transaction('I') { }
    void processTransaction(StoreInventory*, CustomerStorage*);

};
#endif
