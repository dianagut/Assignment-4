// ------------------------------------------- ReturnCommand.h ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Return transaction
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: will process the return transaction
// --------------------------------------------------------------------------------------------------------------------

#ifndef Return_h
#define Return_h

#include "BorrowOrReturn.h"

class Return : public BorrowOrReturn {
public:
    Return() : BorrowOrReturn('R') { } // constructor
    void innerProcess(Movie*, Customer*); //inner proccess of the return transaction
};
#endif
