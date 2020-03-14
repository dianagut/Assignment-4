// ------------------------------------------------ store -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will Implement the transactioFactory
// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------


#ifndef Store_h
#define Store_h

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "HashMap.h"
#include "StoreInventory.h"
#include "CustomerStorage.h"
using namespace std;

class Store {
public:
    Store(); //constructor
    void loadMovies(string); // reads in movie information from movie file
    void loadCustomers(string); // reads in customer information from customer file
    void runCommands(string); // reads and runs commands file
    
private:
    CustomerStorage customers;
    StoreInventory inventory;
};
#endif /* Store_hpp */
