// ------------------------------------------------ CustomerStorage ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will Implement the customer storage
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: files will be formatted correctly
// --------------------------------------------------------------------------------------------------------------------

#include "CustomerStorage.h"

using namespace std;

// ---------------------constructor--------------------------------
// Constructor: default constructor
// preconditions: none
// postconditions: sets fname, lname, and customerID
// -------------------------------------------------------------------------
CustomerStorage::CustomerStorage()
{

}

// ---------------------destructor--------------------------------
// destructor: deallocates memory
// preconditions: none
// postconditions: frees memory 
// ------------------------------------------------------------------
CustomerStorage::~CustomerStorage() 
{
   

}

// ---------------------addcustomer--------------------------------
// addcustomer: adds customer
// preconditions: none
// postconditions: adds customer ID
// ------------------------------------------------------------------
void CustomerStorage::addCustomer(Customer* customer) 
{
    if (customer && customer->getID()) 
    {
        customers.insert(customer->getID(), customer);
        Customer* t;
        customers.retrieve(customer->getID(), t);
        if (!t || t->getID() != customer->getID()) 
        {
            cerr << customer->getID() << " not found " << endl;
        }
    }
}

// ---------------------findcustomer--------------------------------
// findcustomer: finds the customer
// preconditions: none
// postconditions: finds the customer 
// ------------------------------------------------------------------
Customer* CustomerStorage::findCustomer(int id) 
{
    Customer *customer;
    return customers.retrieve(id, customer) ? customer : NULL;
}

// ---------------------listIDs--------------------------------
// addcustomer: list customer IDs
// preconditions: none
// postconditions: displays customer ids
// ------------------------------------------------------------------
void CustomerStorage::listIds() 
{
    int keys[1000];
    int count = customers.getKeys(keys);
    for(int i = 0 ; i <= count; i++) 
    {
        cout << i << ": " << keys[i] << "\n";
    }
    cout << "--" << std::endl;
}
