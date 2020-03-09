// ----------------------------------------------- MovieFactory.h -----------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will Implement the MovieFactory
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------


#ifndef MovieFactory_hpp
#define MovieFactory_hpp

#include "Movie.h"

class MovieFactory {
public:
    static Movie* createMovieFromLine(std::string);
};

#endif /* MovieFactory_hpp */
