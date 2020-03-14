// --------------------------------------------- MovieFactory.cpp -----------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Creates a new movie from movie file
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: new movie will be created from reading in movie type
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <sstream>
#include <istream>
#include "MovieFactory.h"
#include "Drama.h"
#include "Comedy.h"
#include "Classics.h"
using namespace std;

// ---------------------createMovieFromLine--------------------------------
// createMovieFromLine: reads in movie type from file and creates movie
// preconditions: There must be a valid movie file
// postconditions: Classic, Drama, or Comedy movie will be created
// -------------------------------------------------------------------------
Movie* MovieFactory::createMovieFromLine(string line)
{
    Movie* answer = NULL; // movie pointer
    if (line.length() > 0) {
        istringstream iss(line);
        string type;
        iss >> type; // read in movie type
        switch (type[0]) {
        case 'D':
            answer = new Drama(); // if D create a new drama movie
            break;
        case 'C':
            answer = new Classics(); // if C create a new classic movie
            break;
        case 'F':
            answer = new Comedy(); // if F create a new comedy movie
            break;
        default:
                cerr << "Movie type " << line[0] << " not recognized :" <<  endl << "\t" << line <<  endl; // print if movie type not recognized
        }
        if (answer) { // if answer is not NULL
            answer->setData(iss); // set movie data
        }
    }
    return answer;
}
