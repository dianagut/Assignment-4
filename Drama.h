
// ------------------------------------------------Drama.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// -------------------------------------------------------------------------------------------------------------------- // Notes on specifications, special algorithms, and assumptions. 
// -------------------------------------------------------------------------------------------------------------------- 

#ifndef Drama_h
#define Drama_h
#include "Movie.h"

class Drama : public Movie {

public:
    Drama();
    Drama(const string&); // constructor
    Drama(const string&, const string&, const int&); // constructor
    std::istream& setData(std::istream& stream);
    static const char TYPE = 'D'; // movieType

protected:
    bool operator==(const Movie&) const;
    bool operator!=(const Movie&) const;
    bool operator>(const Movie&) const;
    bool operator<(const Movie&)const;
    std::ostream& toOutput(std::ostream&) const;
};

#endif /* Drama_h */
