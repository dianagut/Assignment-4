// ------------------------------------------------ transactionFactory -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Will create a new transaction
// --------------------------------------------------------------------------------------------------------------------
// Asumptions: Will create a new transaction of type borrow, return, history or inventory
// -------------------------------------------------------------------------------------------------------------------- 

#include "transactionFactory.h"
using namespace std;

// ---------------------createTransaction--------------------------------
// createTransaction: reads in command and identifies transaction type
// preconditions: Takes in command as string
// postconditions: If transaction exits will create a new transaction
// -------------------------------------------------------------------------
Transaction* TransactionFactory::createTransaction(string line)
{
    Transaction* transaction = NULL; //create a new transaction
    if (line.length() > 0) { // if the line in is not empty
        istringstream iss(line);
        string type;
        iss >> type; // read in transaction type

        switch (type[0]) // identifies whether the transaction is borrow, return, history, or inventory
        {
        case 'B':
            transaction = new Borrow();
            break;
        case 'R':
            transaction = new Return();
            break;
        case 'H':
            transaction = new History();
            break;
        case 'I':
            transaction = new Inventory();
            break;
        default: // if it is an invalid transaction
            cerr << type << " is not a valid command"<< endl;
                delete transaction;
            break;
        }
        if (transaction) {
            transaction->setData(line);//set the data
        }
    }
    return transaction;
}
