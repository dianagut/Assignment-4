// ------------------------------------------- ReturnCommand.h ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#ifndef Return_h
#define Return_h

#include "BorrowOrReturn.h"

class Return : public BorrowOrReturn {
public:
    Return() : BorrowOrReturn('R') { }
    void innerProcess(Movie*, Customer*);
};
#endif
