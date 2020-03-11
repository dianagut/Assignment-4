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

#include "BorrowOrReturn.h"

class Borrow : public BorrowOrReturn {
public:
    Borrow() : BorrowOrReturn('B') { }
    void innerProcess(Movie*, Customer*);
};
#endif
