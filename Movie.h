//
//  Movie.h
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#ifndef Movie_h
#define Movie_h
#include <string>
using namespace std;

 class Movie {
     
 public:
     // destructor
     virtual ~Movie() {
         
     };
     
     // returns movie information
     virtual void createMovie(string &data);
        
     // increase stock
     virtual bool increaseStock(int);
     
     // decrease stock
     virtual bool descreaseStock(int);
     
     // get movie's stock information
     virtual int getStock();
     
     // overloaded functions
     bool operator==(const Movie*) const;
     bool operator!=(const Movie*) const;
     bool operator>(const Movie*) const;
     bool operator<(const Movie*)const;
     
 protected:
     Movie(); // constructor
     
     char movieType;
     string director;
     int stock;
     string title;
     int releaseYear;
 };

#endif /* Movie_h */
