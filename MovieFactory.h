// ----------------------------------------------- MovieFactory.h -----------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will Implement the MovieFactory
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: Movie will be created
// --------------------------------------------------------------------------------------------------------------------


#ifndef MovieFactory_hpp
#define MovieFactory_hpp

#include "Movie.h"
using namespace std;

class MovieFactory {
public:
    static Movie* createMovieFromLine(string);//will create a new movie 
};

#endif /* MovieFactory_hpp */
