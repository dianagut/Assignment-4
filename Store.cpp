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

Store::Store() {

}

void Store::loadMovies(std::string fileName) {
    if (fileName.empty()) {
        throw std::invalid_argument("moviesFile was not provided");
    }
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
    if (fileName.empty()) {
        throw std::invalid_argument("customersfile was not provided");
    }
    std::ifstream infile(fileName);
    std::string line;
    
    while (std::getline(infile, line))
    {
        Customer *c = new Customer();
        c->setData(infile);
        customers.put(c->getID(), c);
    }
    
    infile.close();
}

void Store::runCommands(std::string filename) {
    if (filename.empty()) {
        throw std::invalid_argument("commandsFile was not provided");
    }
    std::ifstream infile(filename);
    std::string line;
    
    while (std::getline(infile, line))
    {
    }
    
    infile.close();
}
