// ------------------------------------------------transaction.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// -------------------------------------------------------------------------------------------------------------------- // Notes on specifications, special algorithms, and assumptions. 
// -------------------------------------------------------------------------------------------------------------------- 

#include "Movie.h"
#include "customer.h"

class Transaction
{
public:
	Transaction();
	virtual ~Transaction();
	virtual bool setData();
	virtual bool action();
	virtual bool output();

protected:
	char Type;
};