// ------------------------------------------------Comedy.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: File creates comedy class
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: File will be formatted correctly
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
    //constructor
    Comedy();
    //default contructor
    Comedy(const string&, const string&, const int&);
    //setsdata
    istream& setData(istream &stream);
    //movietype
    static const char TYPE = 'F'; 
    //< overload
    bool operator<(const Movie&)const;
    //getter for hash key
    string getHashKey() ;
protected:
    ostream& toOutput(ostream &) const;
};
#endif /* Comedy_h */
