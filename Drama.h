//
//  Drama.h
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#ifndef Drama_h
#define Drama_h
#include "Movie.h"

class Drama: public Movie {
    
public:
    Drama();
    Drama(const string&); // constructor
    Drama(const string&, const string&, const int&); // constructor
    
    virtual ~Drama(); // destructor
    
    static const char TYPE = 'D'; // movieType
    
protected:
    bool operator==(const Movie&) const;
    bool operator!=(const Movie&) const;
    bool operator>(const Movie&) const;
    bool operator<(const Movie&)const;
};

#endif /* Drama_h */
