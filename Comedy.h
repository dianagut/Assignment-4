//
//  Comedy.h
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#ifndef Comedy_h
#define Comedy_h
#include <string>
#include "Movie.h"
using namespace std;

class Comedy: public Movie {
    
public:
    Comedy();
    Comedy(const string&, const string&, const int&); // constructor
    
    virtual ~Comedy(); // destructor
    
    static const char TYPE = 'F'; // movieType
    
protected:
    bool operator==(const Movie&) const;
    bool operator!=(const Movie&) const;
    bool operator>(const Movie&) const;
    bool operator<(const Movie&)const;
};
#endif /* Comedy_h */
