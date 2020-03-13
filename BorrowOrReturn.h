// ------------------------------------------- BorrowOrReturn.h ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This file contains the class borroworeturn
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: file will be formatted correctly. 
// --------------------------------------------------------------------------------------------------------------------

#ifndef BorrowOrReturn_h
#define BorrowOrReturn_h

#include <string>
#include "transaction.h"
#include "Movie.h"
#include "Customer.h"

using namespace std;

class BorrowOrReturn : public Transaction {
public:
    BorrowOrReturn(char t) : Transaction(t) { }
    char getMediaType() { return mediaType; }
    char getMovieType() { return movieType; }
    string getMovieData() { return movieData; }
    void setData(string);
    void processTransaction(StoreInventory* , CustomerStorage* );
    virtual void innerProcess(Movie*, Customer*) { };
protected:
    char mediaType;
    char movieType;
    string movieData;
};
#endif /* BorrowOrReturn_h */
