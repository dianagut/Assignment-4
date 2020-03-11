// ------------------------------------------------ CustomerStorage ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will Implement the transactioFactory
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#include "CustomerStorage.h"

CustomerStorage::~CustomerStorage() {
    
}

void CustomerStorage::addCustomer(Customer *c) {
    if (c && c->getID()) {
        customers.put(c->getID(), c);
    }
}

Customer* CustomerStorage::findCustomer(int id) {
    Customer *c;
    return customers.get(id, c) ? c : NULL;
}
