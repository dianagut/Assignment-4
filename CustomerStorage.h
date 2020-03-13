// ------------------------------------------------ CustomerStorage ---------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will Implement the transactioFactory
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#ifndef CustomerStorage_h
#define CustomerStorage_h

#include "Customer.h"
#include "HashMap.h"

class CustomerStorage {
public:
    ~CustomerStorage();
    void addCustomer(Customer *);
    Customer* findCustomer(int);
    void listIds();
private:
    struct CustomerHash {
        unsigned long operator()(const int& k) const
        {
            return k % TABLE_SIZE;
        }
    };
    
    HashMap<int, Customer*, CustomerHash> customers;
    
};

#endif /* CustomerStorage_h */
