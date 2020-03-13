// ------------------------------------------------Borrow.cpp----------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This is the implementation of the borrow class. 
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: input will be formatted correctly
// --------------------------------------------------------------------------------------------------------------------



#include <iterator>
#include <algorithm>
#include "Borrow.h"

using namespace std;

// ---------------------InnerProcess--------------------------------
// InnerProcess: borrows a movie for a customer
// preconditions: Takes in a movie and customer as param
// postconditions: Checks if enough stock to borrow movie
// -------------------------------------------------------------------------
void Borrow::innerProcess(Movie* movie, Customer* customer) 
{
    if (!movie->descreaseStock(1)) {
        cerr << "Not enough of " << movieData << endl;
    } else {
        customer->storeHistory(rawCommand);
        customer->doBorrow(movie);
    }
}
