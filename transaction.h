// ------------------------------------------------transaction.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// -------------------------------------------------------------------------------------------------------------------- // Notes on specifications, special algorithms, and assumptions. 
// -------------------------------------------------------------------------------------------------------------------- 

#include "Movie.h"
#include "Customer.h"
#include <string>
#include <sstream>
using namespace std;

class Transaction
{
public:
	Transaction();
	virtual ~Transaction();
	virtual void processTransaction();
	virtual bool customerCheck(Customer* customer, int ID);


protected:
	char Type;
};
