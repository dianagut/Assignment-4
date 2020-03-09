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
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Movie.h"
using namespace std;

class Comedy: public Movie {
    
public:
    Comedy();
    Comedy(const string&, const string&, const int&); // constructor
    std::istream& setData(std::istream &stream);
    static const char TYPE = 'F'; // movieType
    bool operator<(const Movie&)const;
    std::string getHashKey() ;
protected:
    std::ostream& toOutput(std::ostream &) const;
};
#endif /* Comedy_h */
