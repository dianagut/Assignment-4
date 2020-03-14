// -------------------------------------------------- main.cpp --------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This file calls the store class to process the files
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: files will be formatted correctly
// --------------------------------------------------------------------------------------------------------------------


#include "Store.h"

int main(int argc, const char * argv[]) 
{
    Store store;
    store.loadMovies("data4movies.txt");
    store.loadCustomers("data4customers.txt");
    store.runCommands("data4commands.txt");
}
