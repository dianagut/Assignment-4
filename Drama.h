// ------------------------------------------------Drama.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This file creates the drama class. Child class of movie.
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: file will be formatted correctly
// --------------------------------------------------------------------------------------------------------------------

#ifndef Drama_h
#define Drama_h
#include "Movie.h"

using namespace std;

class Drama: public Movie {
    
public:
    //constructor
    Drama();
    //overload constructor
    Drama(const string&);
    //overload constructor
    Drama(const string&, const string&, const int&); 
    //setdata
    istream& setData(istream &stream);
    //movieType
    static const char TYPE = 'D'; 
    //operator <
    bool operator<(const Movie&)const;
    string getHashKey() ;
protected:
    ostream& toOutput(ostream &) const;
};

#endif /* Drama_h */
