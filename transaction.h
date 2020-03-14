// ------------------------------------------------transaction.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will implement the transaction class
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: Data will start being read to get all information for transaction
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
	Transaction(char); //constructor
	virtual ~Transaction(); //virtual desctructor
    virtual void processTransaction(StoreInventory*, CustomerStorage*){};//processes a new transaction
	virtual bool customerCheck(Customer* customer, int ID);//checks if customer ID exists
    virtual void setData(string);//sets data for command line
    int getCustomerId() { return customerId; } //returns customer ID

protected:
	char Type;
    int customerId = -1;
    string rawCommand;
};
#endif
