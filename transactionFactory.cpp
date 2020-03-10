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

Transaction* TransactionFactory::createTransaction(std::string line)
{
    Transaction* transaction = NULL;
    if (line.length() > 0) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        switch (type[0])
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
        default:
                cout << type << " is not a valid command\n";
            transaction = NULL;
            break;
        }
        if (transaction) {
            transaction->setData(line);
        }
    }
    return transaction;
}
