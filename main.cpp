// -------------------------------------------------- main.cpp --------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------


#include "Store.h"

int main(int argc, const char * argv[]) {
    Store store;
    store.loadMovies("data4movies.txt");
    store.loadCustomers("data4customers.txt");
    store.runCommands("data4commands.txt");
}
