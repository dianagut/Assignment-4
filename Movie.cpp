// ------------------------------------------------ Movie.cpp -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: this implements the movie class 
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: files will be formatted correctly
// -------------------------------------------------------------------------------------------------------------------- 

#include "Movie.h"
#include <iostream>
#include <string>
#include <sstream>
#include <istream>
#include "Drama.h"
#include "Comedy.h"
#include "Classics.h"
#include "StringUtils.h"

using namespace std;

// ---------------------constructor--------------------------------
// constructor: default constructor
// preconditions: none
// postconditions: sets movieType, director, title, releaseyear, stock and mediatype
// -------------------------------------------------------------------------
Movie::Movie(char movieType, char mediaType) 
{
    this->movieType = movieType;
    director = "";
    title = "";
    releaseYear = 0;
    stock = 0;
    this->mediaType = mediaType;
}

// ---------------------setData--------------------------------
// setData: sets data
// preconditions: none
// postconditions: sets data from file
// -------------------------------------------------------------------------
istream& Movie::setData(istream& stream)
{
    string temp;
    getline(stream, temp, ',');
    stock = stoi(temp);
    getline(stream, temp, ',');
    director = StringUtils::trim(temp);
    getline(stream, temp, ',');
    title = StringUtils::trim(temp);
    return stream;
}

// --------------------increaseStock--------------------------------
// increaseStock: increases stock
// preconditions: none
// postconditions: increases stock when returned
// -------------------------------------------------------------------------
bool Movie::increaseStock(int add) 
{
    stock += add;
    return true;
}

// --------------------decreaseStock--------------------------------
// decreaseStock: decrease stock
// preconditions: none
// postconditions: decreases stock when borrowed must never reach less than 0
// -------------------------------------------------------------------------
bool Movie::descreaseStock(int subtract) 
{
    if (stock <= 0) 
    {
        stock = 0 ; // this can't go below zero for any reason
        return false;
    }
    stock -= subtract;
    return true;
}

// --------------------operator<--------------------------------
// operator<: overload < operator 
// preconditions: none
// postconditions: checks if lhs < rhs 
// -------------------------------------------------------------------------
bool Movie::operator<(const Movie &movie) const 
{
    return movieType < movie.movieType;
}

// --------------------operator>--------------------------------
// operator>: overload > operator 
// preconditions: none
// postconditions: checks if lhs > rhs 
// -------------------------------------------------------------------------
bool Movie::operator>(const Movie& movie) const 
{
    return !(*this < movie);
}

// --------------------operator==--------------------------------
// operator==: overload == operator 
// preconditions: none
// postconditions: checks if lhs == rhs 
// -------------------------------------------------------------------------
bool Movie::operator==(const Movie& movie) const 
{
    return movieType == movie.movieType &&
    director == movie.director &&
    title == movie.title &&
    releaseYear == movie.releaseYear;
}

// --------------------operator!=--------------------------------
// operator!=: overload != operator 
// preconditions: none
// postconditions: checks if lhs != rhs 
// -------------------------------------------------------------------------
bool Movie::operator!=(const Movie& movie)const 
{
    return !(*this == movie);
}

// --------------------toOuput--------------------------------
// toOuput: creates movie output
// preconditions: none
// postconditions: displays output in proper format
// -------------------------------------------------------------------------
ostream& Movie::toOutput(std::ostream& output) const 
{
    output << movieType << ", " << stock << ", " << director << ", " << title;
    return output;
}

// --------------------operator<<--------------------------------
// operator<: overload << operator 
// preconditions: none
// postconditions: overloads the << for display
// -------------------------------------------------------------------------
ostream& operator<<(ostream& output, const Movie& movie) 
{
    return movie.toOutput(output);
}
