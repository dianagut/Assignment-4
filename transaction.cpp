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

Transaction::Transaction()
{
}

Transaction::~Transaction()
{
}

void Transaction::processTransaction()
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
