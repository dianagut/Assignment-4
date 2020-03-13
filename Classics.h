// ------------------------------------------------Classics.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This file is to create a classics class. It is the child class of Movie. 
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: Data will be formatted correctly
// --------------------------------------------------------------------------------------------------------------------

#ifndef Classics_h
#define Classics_h
#include "Movie.h"

class Classics : public Movie {

public:
    //constructor
    Classics();
    Classics(const string&); // Overloaded constructor

    Classics(const string&, const string&, const string&, const int&); //overloaded constructor

    istream& setData(istream& stream); //
    static const char TYPE = 'C'; // movieType
    
    string getHashKey(); //get hash key for classics
    bool operator<(const Movie&)const; //<< operator
    bool operator==(const Movie& ) const;//== operator
protected:
    int month; // release date
    string majorActor; // first name, last name

    ostream& toOutput(std::ostream&) const; //overload output operator
};
#endif /* Classics_h */
