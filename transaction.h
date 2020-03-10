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
#include "StoreInventory.h"
#include "CustomerStorage.h"
using namespace std;

#ifndef Transaction_h
#define Transaction_h
class Transaction
{
public:
	Transaction(char);
	virtual ~Transaction();
	virtual void processTransaction(StoreInventory*, CustomerStorage*);
	virtual bool customerCheck(Customer* customer, int ID);
    virtual void setData(std::string);
    int getCustomerId() { return customerId; }

protected:
	char Type;
    int customerId = -1;
    std::string rawCommand;
};
#endif
