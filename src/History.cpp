// ----------------------------------------------- HistoryCommand.cpp -------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include "History.h"

void History::processTransaction(StoreInventory*, CustomerStorage* customers) {
    Customer *c = customers->findCustomer(customerId);
    if (c) {
        c->showHistory(std::cout);
    } else {
        std::cerr << "Customer " << customerId << " was not found" <<  std::endl;
    }
}

void History::setData(std::string line) {
    Transaction::setData(line);
    std::istringstream iss(line);
    std::string temp;
    iss >> temp;
    iss >> customerId;
}
