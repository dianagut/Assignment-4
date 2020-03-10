// ------------------------------------------- BorrowOrReturn.h ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#ifndef BorrowOrReturn_h
#define BorrowOrReturn_h

#include "transaction.h"
#include "Movie.h"
#include "Customer.h"

class BorrowOrReturn : public Transaction {
public:
    BorrowOrReturn(char t) : Transaction(t) { }
    char getMediaType() { return mediaType; }
    char getMovieType() { return movieType; }
    std::string getMovieData() { return movieData; }
    void setData(std::string);
    void processTransaction(StoreInventory* , CustomerStorage* );
    virtual void innerProcess(Movie*, Customer*) { };
protected:
    char mediaType;
    char movieType;
    std::string movieData;
};
#endif /* BorrowOrReturn_h */
