// ------------------------------------------- BorrowOrReturn.h ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Implements the borroworreturn class
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: file will be formatted correctly. 
// --------------------------------------------------------------------------------------------------------------------

#include <algorithm>
#include "BorrowOrReturn.h"

using namespace std;

// ---------------------BorroworReturn--------------------------------
// Constructor: processes a borrow or return.
// preconditions: takes in inventory and customer
// postconditions: checks if item exists 
// ------------------------------------------------------------------------
void BorrowOrReturn::processTransaction(StoreInventory* inventory, CustomerStorage* customers) 
{
    Customer *customer = customers->findCustomer(customerId);
    if (customer) 
    {
        Movie *movie = inventory->findItem(movieData);
        if (!movie) 
        {
            cerr << "Movie " << movieData << " was not found" <<  std::endl;
            return;
        }
        if (mediaType != movie->getMediaType()) 
        {
            std::cerr << "Movie " << movieData << " not available for mediaType " << mediaType <<  std::endl;
            return;
        }
        innerProcess(movie, customer);
    } else 
    {
        cerr << "Customer " << customerId << " was not found" <<  std::endl;
    }
}

// ---------------------setData--------------------------------
// setData: sets data from file.
// preconditions: takes in a string line
// postconditions: sets data from the file
// ------------------------------------------------------------------------
void BorrowOrReturn::setData(string line) 
{
    Transaction::setData(line);
    istringstream iss(line);
    string temp;
    iss >> temp;
    iss >> customerId;
    iss >> mediaType;
    iss >> movieType;
    getline(iss, movieData);
    movieData.erase(remove(movieData.begin(), movieData.end(), ','), movieData.end()); // remove , from string
    StringUtils::trim(movieData);
}
