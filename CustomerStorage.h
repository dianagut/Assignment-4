// ------------------------------------------------ CustomerStorage ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will Implement the customerstorage
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: file will be formatted correctly
// --------------------------------------------------------------------------------------------------------------------

#ifndef CustomerStorage_h
#define CustomerStorage_h

#include "Customer.h"
#include "HashTable.h"

class CustomerStorage 
{
public:
    
    //constructor
    CustomerStorage();
    //destructor
    ~CustomerStorage();
    //adds the customer
    void addCustomer(Customer*);
    //finds the customer
    Customer* findCustomer(int);
    //displays the ids
    void listIds();
private:
    //struct for customer
    struct CustomerHash 
    {
        unsigned long operator()(const int& k) const
        {
            return k % TABLE_SIZE;
        }
    };
    // Customers indexed by the customerID
    // store only pointers to customers
    HashTable<int, Customer*, CustomerHash> customers;
};

#endif /* CustomerStorage_h */
