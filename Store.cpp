// ------------------------------------------------ store -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will Implement the transactioFactory
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#include "Store.h"
#include "MovieFactory.h"

Store::Store(std::string moviesFile, std::string customersFile) {
    if (moviesFile.empty()) {
        throw std::invalid_argument("moviesFile was not provided");
    }
    if (customersFile.empty()) {
        throw std::invalid_argument("customersfile was not provided");
    }
    loadMovies(moviesFile);
    loadCustomers(customersFile);
}

void Store::loadMovies(std::string fileName) {
    std::ifstream infile(fileName);
    std::string line;
    
    while (std::getline(infile, line))
    {
        Movie *m = MovieFactory::createMovieFromLine(line);
        if (m) {
            inventory.addItem(m);
        }
    }
    infile.close();
}

void Store::loadCustomers(std::string fileName) {
    std::ifstream infile(fileName);
    std::string line;
    
    while (std::getline(infile, line))
    {
        Customer c;
        c.setData(infile);
    }
    
    infile.close();
}
