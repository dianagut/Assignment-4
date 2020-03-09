<<<<<<< HEAD
//
//  main.cpp
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Movie.h"
#include <vector>
#include "Inventory.hpp"

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
    Inventory inv;
    
    while (std::getline(infile, line))
    {
        Movie *m = Movie::fromLine(line);
        if (m) {
            inv.addItem(m);
            insert(m);
        }
    }
    
    std::cout << "Inventory:\n" << inv << "\n";
}
=======
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Movie.h"
#include <vector>
#include "Inventory.h"
using namespace std;

int main() {
    ifstream infile("data4movies.txt");
    string line;
    Inventory inv;

    while (getline(infile, line))
    {
        Movie* m = Movie::fromLine(line);
        if (m) {
            inv.addItem(m);
        }
    }


}
>>>>>>> 888d2ed62f8022b0126b4d6233bc04ad21e0482e
