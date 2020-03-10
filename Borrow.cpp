// ------------------------------------------------BorrowCommand.cpp----------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------


#include <typeinfo>
#include "Borrow.h"

void Borrow::processTransaction(StoreInventory* inventory, CustomerStorage* customers) {
    Customer *c = customers->findCustomer(customerId);
    if (c) {
        Movie *m = inventory->findItem(movieData);
        if (!m) {
            cout << "Movie " << movieData << " was not found\n";
            return;
        }
        if (!m->descreaseStock(1)) {
            cout << "Not enough of " << movieData << "\n";
        }
        c->storeHistory(Type);
    } else {
        cout << "Customer " << customerId << " was not found\n";
    }
}

std::istream& Borrow::setData(std::istream& stream)
{
    std::string temp;
    stream >> customerId;
    stream >> mediaType;
    stream >> movieType;
    std::getline(stream, movieData);
    movieData.erase(remove(movieData.begin(), movieData.end(), ','), movieData.end()); //remove A from string
    StringUtils::trim(movieData);
    return stream;
}
