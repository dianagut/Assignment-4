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
    // free memory for all customers
}

void CustomerStorage::addCustomer(Customer *c) {
    if (c && c->getID()) {
        customers.put(c->getID(), c);
        Customer *t;
        customers.get(c->getID(), t);
        if (!t || t->getID() != c->getID()) {
            std::cerr << c->getID() << " not found " << std::endl;
        }
    }
}

Customer* CustomerStorage::findCustomer(int id) {
    Customer *c;
    return customers.get(id, c) ? c : NULL;
}

void CustomerStorage::listIds() {
    int keys[1000];
    int count = customers.getKeys(keys);
    for(int i = 0 ; i <= count; i++) {
        std::cout << i << ": " << keys[i] << "\n";
    }
    std::cout << "--" << std::endl;
}
