// ------------------------------------------------Classics.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#ifndef Classics_h
#define Classics_h
#include "Movie.h"

class Classics : public Movie {

public:

    Classics();
    Classics(const string&); // constructor

    Classics(const string&, const string&, const string&, const int&); // constructor

    std::istream& setData(std::istream& stream);
    static const char TYPE = 'C'; // movieType
    
    std::string getHashKey() ;
    bool operator<(const Movie&)const;
    bool operator==(const Movie& ) const;
protected:
    int month; // release date
    string majorActor; // first name, last name

    std::ostream& toOutput(std::ostream&) const;
};
#endif /* Classics_h */
