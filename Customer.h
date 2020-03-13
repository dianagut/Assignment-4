//------------------------------------------------Customer.h------------------------------------------------------ -
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions. 
// --------------------------------------------------------------------------------------------------------------------  

#ifndef Customer2_h
#define Customer2_h

#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "HashMap.h"

using namespace std;

class Customer {
    friend ostream & operator<<(ostream &, const Customer &);

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

    bool setData(istream&);
    void storeHistory(std::string);
    void showHistory(ostream &);
    void doBorrow(Movie*);
    bool doReturn(Movie *m);
    
private:
    int customerID;
    string firstName;
    string lastName;
    std::vector<std::string> history;
    // list of borrowed movies, indexed by movie sorting string
    // we store how many of the movie the customer has
    HashMap<std::string, int, MovieHash> borrowed;
};

#endif
