//------------------------------------------------Customer.h------------------------------------------------------ -
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// -------------------------------------------------------------------------------------------------------------------- // Notes on specifications, special algorithms, and assumptions. 
// --------------------------------------------------------------------------------------------------------------------  

#ifndef Customer2_h
#define Customer2_h

#include <string> 

using namespace std;

class Customer {

public:
    Customer(); // default constructor
    Customer(string, string, int); // constructor

    ~Customer(); // destructor

  //  bool transaction(char, Movie*); // adds transaction to customer history

    // getter methods
    int getID() const;
    string getName() const;
    string getFirst() const; // getFirstName()
    string getLast() const;  // getLastName()


private:
    int customerID;
    string firstName;
    string lastName;
};

#endif