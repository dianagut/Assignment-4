// ------------------------------------------------Comedy.cpp -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Implementation of comedy class
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: File will be formatted correctly
// --------------------------------------------------------------------------------------------------------------------

#include <typeinfo>
#include "Comedy.h"

using namespace std;

// ---------------------Constructor--------------------------------
// constructor: Default constructor
// preconditions: none
// postconditions: sets default director, title, year
// -------------------------------------------------------------------------
Comedy::Comedy() : Movie(Comedy::TYPE) 
{
    director = "";
    title = "";
    releaseYear = 0;
}

// ---------------------Constructor--------------------------------
// constructor: overloaded constructor
// preconditions: none
// postconditions: sets default director, title, year
// --------------------------------------------------------------------------
Comedy::Comedy(const string& director, const string& title, const int& year) : Movie(Comedy::TYPE) 
{
    this->director = director;
    this->title = title;
    releaseYear = year;
}

// ---------------------operator<--------------------------------
// operator<: overload <
// preconditions: takes in a movie
// postconditions: checks if rhs > lhs
// -------------------------------------------------------------------------
bool Comedy::operator<(const Movie &movie) const 
{
    try 
    {
        const Comedy& other = static_cast<const Comedy&>(movie);
        return title < other.title && releaseYear < other.releaseYear;
    } 
    catch (const std::bad_cast& e) 
    {
        return Movie::operator<(movie);
    }
    return false;
}

// ---------------------getHashKey--------------------------------
// getHashKey: gets hashkey
// preconditions: none
// postconditions: checks if empty and returns hashkey
// -------------------------------------------------------------------------
std::string Comedy::getHashKey() 
{
    if (hashKey.empty()) 
    {
        hashKey = title + " " + to_string(releaseYear);
    }
    return hashKey;
}

// ---------------------setData--------------------------------
// setData: sets movie data
// preconditions: none
// postconditions: sets movie data from file
// -------------------------------------------------------------------------
istream& Comedy::setData(istream &stream)
{
    Movie::setData(stream);
    string temp;
    getline(stream, temp, ',');
    releaseYear = stoi(temp);
    return stream;
}

// ---------------------ostream--------------------------------
// ostream: output operator 
// preconditions: none
// postconditions: returns desired output
// -------------------------------------------------------------------------
ostream & Comedy::toOutput(ostream &output) const 
{
    Movie::toOutput(output);
    output << ", " << releaseYear;
    return output;
}
