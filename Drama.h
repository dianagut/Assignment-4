<<<<<<< HEAD
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
    std::istream& setData(std::istream &stream);
    static const char TYPE = 'D'; // movieType
    bool operator<(const Movie&)const;
    std::string getHashKey() ;
protected:
    std::ostream& toOutput(std::ostream &) const;
};

#endif /* Drama_h */
=======

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
>>>>>>> 888d2ed62f8022b0126b4d6233bc04ad21e0482e
