// ------------------------------------------------ store -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will Implement the transactioFactory
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------


#ifndef Store_h
#define Store_h

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "HashMap.h"
#include "StoreInventory.h"
#include "Customer.h"

class Store {
public:
    Store(std::string, std::string);
private:
    void loadMovies(std::string);
    void loadCustomers(std::string);
    HashMap customers;
    StoreInventory inventory;
};
#endif /* Store_hpp */
