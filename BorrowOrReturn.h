// ------------------------------------------- BorrowOrReturn.h ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This file contains the class borroworeturn. Child class of transaction.
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
    //constructor
    BorrowOrReturn(char t) : Transaction(t) { }
    //getter for media type 
    char getMediaType() { return mediaType; }
    //getter for movie type 
    char getMovieType() { return movieType; }
    //getter for movie data
    string getMovieData() { return movieData; }
    //set data from file
    void setData(string);
    //Processed transactions
    void processTransaction(StoreInventory* , CustomerStorage* );
    //inner process
    virtual void innerProcess(Movie*, Customer*) { };
protected:
    char mediaType;
    char movieType;
    string movieData;
};
#endif /* BorrowOrReturn_h */
