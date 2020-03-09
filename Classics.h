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
    
    std::istream& setData(std::istream &stream);
    static const char TYPE = 'C'; // movieType
    
    std::string getHashKey() ;
    bool operator<(const Movie&)const;
    
protected:

    int month; // release date
    string majorActor; // first name, last name
    
    std::ostream& toOutput(std::ostream &) const;
    
};
#endif /* Classics_h */
