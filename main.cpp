// -------------------------------------------------- main.cpp --------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Movie.h"
#include <vector>
#include "StoreInventory.h"
#include "MovieFactory.h"

Movie **movies = new Movie*[50];
static int movieCount = 0;

void insert(Movie *movie) {
    int place = 0;
    while((place < movieCount ) && *movies[place] <  *movie ) {
        place++;
    }
    if (place < movieCount) {
        for(int i = movieCount; i > place; i--) {
            movies[i] = movies[i-1];
        }
    }
    movieCount++;
    movies[place] = movie;
}

int main(int argc, const char * argv[]) {
    std::ifstream infile("data4movies.txt");
    std::string line;
    StoreInventory inv;
    
    while (std::getline(infile, line))
    {
        Movie *m = MovieFactory::createMovieFromLine(line);
        if (m) {
            inv.addItem(m);
            insert(m);
        }
    }
    
    std::cout << "Inventory:\n" << inv << "\n";
}
