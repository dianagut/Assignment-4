// ------------------------------------------------ transactionFactory -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// -------------------------------------------------------------------------------------------------------------------- 



#include "transactionFactory.h"


using namespace std;

Transaction* TransactionFactory::createTransaction(char& answer)
{
    Transaction* transaction = NULL;

    switch (answer)
    {
    case 'B':
        transaction = new BorrowCommand();
        break;
    case 'R':
        transaction = new ReturnCommand();
        break;
    case 'H':
        transaction = new HistoryCommand();
        break;
    case 'T':
        transaction = new InventoryCommand();
        break;
    default:
        transaction = NULL;
        break;
    }
    return transaction;
}
