// ------------------------------------------ BorrowCommand.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#ifndef Borrow_h
#define Borrow_h

#include "transaction.h"

class Borrow : public Transaction {
public:
    Borrow() : Transaction('B') { }
    char getMediaType() { return mediaType; }
    char getMovieType() { return movieType; }
    std::string getMovieData() { return movieData; }
    void processTransaction(StoreInventory*, CustomerStorage*);
    void setData(std::string);
    
private:
    char mediaType;
    char movieType;
    std::string movieData;
};
#endif
