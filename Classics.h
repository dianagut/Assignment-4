//
//  Classics.h
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#ifndef Classics_h
#define Classics_h
#include "Movie.h"

class Classics: public Movie {
    
public:
    
    Classics();
    Classics (const string&); // constructor
    
    Classics(const string&, const string&, const string&, const int&); // constructor
    
     ~Classics() // destructor
    
    
    static const char TYPE = 'C'; // movieType
    
protected:
    bool operator==(const Movie&) const;
    bool operator!=(const Movie&) const;
    bool operator>(const Movie&) const;
    bool operator<(const Movie&)const;
    
    int month; // release date
    string majorActor; // first name, last name
};
#endif /* Classics_h */
