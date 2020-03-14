// ------------------------------------------------ Movie.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This file creates a movie class. 
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: files will be formatted correctly 
// --------------------------------------------------------------------------------------------------------------------

#ifndef Movie_h
#define Movie_h
#include <string>
#include "StringUtils.h"

using namespace std;

 class Movie {
     friend ostream & operator<<(ostream &, const Movie &);
 public:
     // destructor
     virtual ~Movie() {
         
     };
     
     // increase stock
     virtual bool increaseStock(int);
     
     // decrease stock
     virtual bool descreaseStock(int);
     
     // overloaded functions
     virtual bool operator==(const Movie&) const;
     virtual bool operator!=(const Movie&) const;
     virtual bool operator>(const Movie&) const;
     virtual bool operator<(const Movie&) const;
     
     virtual istream& setData(istream &);

     // getters / setters
     char getMovieType() { return movieType; }
     string getTitle() { return title; }
     string getDirector() { return director; }
     int getStock() { return stock; }
     int getReleaseYear() { return releaseYear; }
     char getMediaType() { return mediaType; }

     virtual string getHashKey() { return title; }
 protected:
     Movie(char, char mediaType = 'D'); // constructor
     virtual ostream& toOutput(ostream &) const;
     
     char mediaType;
     char movieType;
     string director;
     int stock;
     string title;
     int releaseYear;

     string hashKey = "";
 };

#endif /* Movie_h */
