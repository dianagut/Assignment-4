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

void Return::processTransaction(StoreInventory*, CustomerStorage*) {
    
}

void Return::setData(std::string line) {
    Transaction::setData(line);
    std::istringstream iss(line);
    std::string temp;
    iss >> temp;
}
