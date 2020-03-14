// ----------------------------------------------- HistoryCommand.cpp -------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This file implements the history class
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: file will be formatted correctly
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include "History.h"

using namespace std;

// ---------------------processTransaction--------------------------------
// processTransaction: processes the transactions
// preconditions: none
// postconditions: processes history
// -------------------------------------------------------------------------
void History::processTransaction(StoreInventory*, CustomerStorage* customers) 
{
    Customer *c = customers->findCustomer(customerId);
    if (c) 
    {
        c->showHistory(cout);
    } 
    else 
    {
        cerr << "Customer " << customerId << " was not found" <<  endl;
    }
}

// ---------------------setData--------------------------------
// setData: sets data
// preconditions: none
// postconditions: reads in data from file
// -------------------------------------------------------------------------
void History::setData(string line) 
{
    Transaction::setData(line);
    istringstream iss(line);
    string temp;
    iss >> temp;
    iss >> customerId;
}
