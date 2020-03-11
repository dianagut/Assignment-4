// ------------------------------------------------transaction.cpp-------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// -------------------------------------------------------------------------------------------------------------------- // Notes on specifications, special algorithms, and assumptions. 
// -------------------------------------------------------------------------------------------------------------------- 

#include "transaction.h"
#include <iostream>
#include <string>

using namespace std;

Transaction::Transaction(char type)
{
    Type = type;
}

Transaction::~Transaction()
{
}

void Transaction::processTransaction(StoreInventory*, CustomerStorage*)
{
}

bool Transaction::customerCheck(Customer* customer, int ID)
{
	if (customer == NULL)
	{
		ostringstream temp;
		temp << ID;
		cout << "Customer ID: " << temp.str() << " doesn't exist." << endl;
		return true;
	}
	return false;
}

void Transaction::setData(std::string line) {
    rawCommand = line;
}
