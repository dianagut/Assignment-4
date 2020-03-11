// ------------------------------------------- BorrowOrReturn.h ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#include <algorithm>
#include "BorrowOrReturn.h"


void BorrowOrReturn::processTransaction(StoreInventory* inventory, CustomerStorage* customers) {
    Customer *customer = customers->findCustomer(customerId);
    if (customer) {
        Movie *movie = inventory->findItem(movieData);
        if (!movie) {
            std::cerr << "Movie " << movieData << " was not found" <<  std::endl;
            return;
        }
        if (mediaType != movie->getMediaType()) {
            std::cerr << "Movie " << movieData << " not available for mediaType " << mediaType <<  std::endl;
            return;
        }
        innerProcess(movie, customer);
    } else {
        std::cerr << "Customer " << customerId << " was not found" <<  std::endl;
    }
}

void BorrowOrReturn::setData(std::string line) {
    Transaction::setData(line);
    std::istringstream iss(line);
    std::string temp;
    iss >> temp;
    iss >> customerId;
    iss >> mediaType;
    iss >> movieType;
    std::getline(iss, movieData);
    movieData.erase(remove(movieData.begin(), movieData.end(), ','), movieData.end()); // remove , from string
    StringUtils::trim(movieData);
}
