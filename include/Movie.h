// ------------------------------------------------ Movie.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#ifndef Movie_h
#define Movie_h
#include <string>
#include "StringUtils.h"
using namespace std;

 class Movie {
     friend std::ostream & operator<<(std::ostream &, const Movie &);
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
     
     // overloaded functions
     virtual bool operator==(const Movie&) const;
     virtual bool operator!=(const Movie&) const;
     virtual bool operator>(const Movie&) const;
     virtual bool operator<(const Movie&)const;
     
     char getMovieType() { return movieType; }
     virtual std::istream& setData(std::istream &);
     
     string getTitle() { return title; }
     string getDirector() { return director; }
     int getStock() { return stock; }
     int getReleaseYear() { return releaseYear; }
     virtual std::string getHashKey() { return title; }
 protected:
     Movie(char); // constructor
     virtual std::ostream& toOutput(std::ostream &) const;
     
     char movieType;
     string director;
     int stock;
     string title;
     int releaseYear;

     std::string hashKey = "";
 };

#endif /* Movie_h */
