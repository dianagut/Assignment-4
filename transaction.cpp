// ------------------------------------------------transaction.cpp-------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Class to create a new transaction
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: Data will start being set in the new transaction
// -------------------------------------------------------------------------------------------------------------------- 

#include "transaction.h"
#include <iostream>
#include <string>

using namespace std;

// ---------------------constructor--------------------------------
// constructor: creates a new transaction of a specific transaction type
// preconditions: Must have a valid transaction type
// postconditions: A new transaction is created
// -------------------------------------------------------------------------
Transaction::Transaction(char type)
{
    Type = type;//assign transaction type
}

// ---------------------destructor--------------------------------
// destructor: frees all memory in transaction
// preconditions: Memory is allocated
// postconditions: memory will be freed
// -------------------------------------------------------------------------
Transaction::~Transaction()
{
    //free all memory in transaction
    
}

// ---------------------customerCheck--------------------------------
// customerCheck: checks if customer exists
// preconditions: Must be a customer object and an int ID
// postconditions: confirm whether the customer exists or not
// -------------------------------------------------------------------------
bool Transaction::customerCheck(Customer* customer, int ID)
{
	if (customer == NULL) //if customer is null
	{
		ostringstream temp;
		temp << ID;// read ID
		cout << "Customer ID: " << temp.str() << " doesn't exist." << endl; //print
		return true;
	}
	return false;
}
// ---------------------setData--------------------------------
// setData: sets data from command line
// preconditions: Takes in command as string
// -------------------------------------------------------------------------
void Transaction::setData(string line) {
    rawCommand = line;
}
