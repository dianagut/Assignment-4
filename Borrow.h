// ------------------------------------------ Borrow.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This file create the borrow class
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: Files will be fomatted correctly.
// --------------------------------------------------------------------------------------------------------------------

#ifndef Borrow_h
#define Borrow_h

#include "BorrowOrReturn.h"

class Borrow : public BorrowOrReturn 
{
public:
    // borrow is represented with a B
    Borrow() : BorrowOrReturn('B') { }
    //process to borrow movie
    void innerProcess(Movie*, Customer*);
};
#endif
