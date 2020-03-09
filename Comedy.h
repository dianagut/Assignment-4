// ------------------------------------------------Comedy.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------


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
