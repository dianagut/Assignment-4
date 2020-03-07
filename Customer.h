//
//  Customer2.h
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#ifndef Customer2_h
#define Customer2_h
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

#endif /* Customer2_h */
