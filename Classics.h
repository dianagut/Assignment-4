//
//  Classics.h
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#ifndef Classics_h
#define Classics_h

class Classics: public Movie {
    
public:
    Classics (const string&); // constructor
    
    Classics(const string&, const int&, const int&); // constructor
    
     ~Classics() // destructor
    
    // returns movie information
    virtual string createMovie() const;
    
    // info for customer transactions
    virtual string creatCustomerHistory() const;
    
    static const char TYPE = 'C'; // movieType
    bool isEqual(const Movie*) const;
    
protected:
    bool operator==(const Movie*) const;
    bool operator!=(const Movie*) const;
    bool operator>(const Movie*) const;
    bool operator<(const Movie*)const;
    
    int month; // release date
    string majorActor; // first name, last name
};
#endif /* Classics_h */
