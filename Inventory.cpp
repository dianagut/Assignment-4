// ------------------------------------------- InventoryCommand.cpp ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: this implemets the inventory class
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: The file will be correctly formatted
// --------------------------------------------------------------------------------------------------------------------

#include "Inventory.h"

// ---------------------processtransaction--------------------------------
// processtransaction: processes transactions
// preconditions: Takes in inventory and customers
// postconditions: displays the inventory
// -------------------------------------------------------------------------
void Inventory::processTransaction(StoreInventory *inventory, CustomerStorage* customers) 
{
    cout << "Current inventory: " << endl;
    cout << *inventory << endl;
}
