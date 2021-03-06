// ------------------------------------------------ transactionFactory -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will Implement the transactioFactory 
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: Will successfully create a new transaction
// -------------------------------------------------------------------------------------------------------------------- 

#pragma once
#include "StoreInventory.h"
#include "transaction.h"
#include "Borrow.h"
#include "History.h"
#include "Inventory.h"
#include "Return.h"
using namespace std;

class TransactionFactory
{
public:
	static Transaction* createTransaction(string); // will create a new transaction
};

