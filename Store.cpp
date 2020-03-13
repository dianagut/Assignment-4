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
#include "transactionFactory.h"

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
        Movie *movie = MovieFactory::createMovieFromLine(line);
        if (movie) {
            inventory.addItem(movie);
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
    
    while (!infile.eof())
    {
        Customer *c = new Customer();
        if(c->setData(infile)) {
            customers.addCustomer(c);
        }
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
        Transaction *t = TransactionFactory::createTransaction(line);
        if (t) {
            t->processTransaction(&inventory, &customers);
        }
    }
    
    infile.close();
}
