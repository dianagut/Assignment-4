// --------------------------------------------- MovieFactory.cpp -----------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will Implement the MovieFactory
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <sstream>
#include <istream>
#include "MovieFactory.h"
#include "Drama.h"
#include "Comedy.h"
#include "Classics.h"

Movie* MovieFactory::createMovieFromLine(std::string line)
{
    Movie* answer = NULL;
    if (line.length() > 0) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;
        switch (type[0]) {
        case 'D':
            answer = new Drama();
            break;
        case 'C':
            answer = new Classics();
            break;
        case 'F':
            answer = new Comedy();
            break;
        default:
                std::cerr << "Movie type " << line[0] << " not recognized :\n\t" << line << "\n";
        }
        if (answer) {
            answer->setData(iss);
        }
    }
    return answer;
}
