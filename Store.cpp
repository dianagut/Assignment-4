// ------------------------------------------------ store -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will Implement the transactioFactory
// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------

#include "Store.h"
#include "MovieFactory.h"
#include "transactionFactory.h"
using namespace std;

// ---------------------constructor--------------------------------
// constructor: creates a new store object
// postconditions: Creates empty store object
// -------------------------------------------------------------------------
Store::Store() {

}

// ---------------------loadMovies--------------------------------
// loadMovies: reads movies file
// preconditions: There must be a movie file
// postconditions: Will create movie objects as it reads in movies
// -------------------------------------------------------------------------
void Store::loadMovies(string fileName) {
    if (fileName.empty()) {// check if file is empty
        throw invalid_argument("moviesFile was not provided"); // if there was no file provided
    }
    ifstream infile(fileName);
    string line;
    
    while (getline(infile, line))//While there is a next line in the file
    {
        Movie *movie = MovieFactory::createMovieFromLine(line); //create a movie
        if (movie) {
            inventory.addItem(movie);//add movie to inventory
        }
    }
    infile.close(); // close file
}

// ---------------------loadCustomers--------------------------------
// loadCustomers: reads in customer file
// preconditions: there must be a customer file
// postconditions: will create customer objects as it reads in custoemrs
// -------------------------------------------------------------------------
void Store::loadCustomers(string fileName) {
    if (fileName.empty()) { //check if file is empty
        throw invalid_argument("customersfile was not provided"); // there was no file found
    }
    ifstream infile(fileName);
    string line;
    
    while (!infile.eof())
    {
        Customer *c = new Customer(); // create a new customer
        if(c->setData(infile)) { //read in data
            customers.addCustomer(c); // add customer to hashmap
        }
    }
    
    infile.close(); //close file
}

// ---------------------runCommands--------------------------------
// runCommands: reads and runs command file
// preconditions: must be a command file
// postconditions: will run commands and create new transactions
// -------------------------------------------------------------------------
void Store::runCommands(string filename) {
    if (filename.empty()) { //check if file is empty
        throw invalid_argument("commandsFile was not provided"); //no file found
    }
    ifstream infile(filename);
    string line;
    
    while (getline(infile, line))
    {
        Transaction *t = TransactionFactory::createTransaction(line); // create a new transaction
        if (t) {
            t->processTransaction(&inventory, &customers); // process the transaction
        }
    }
    
    infile.close(); // close file
}
