// ------------------------------------------------Drama.cpp -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: implements the drama class. Child class of movie
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: file will be formatted correctly
// -------------------------------------------------------------------------------------------------------------------- 

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include "Drama.h"

using namespace std;

// ---------------------constructor--------------------------------
// Constructor: default constructor
// preconditions: none
// postconditions: stock, director, title, and release year
// -------------------------------------------------------------------------
Drama::Drama() : Movie(Drama::TYPE) 
{
}

// ---------------------constructor--------------------------------
// Constructor: overloaded constructor
// preconditions: none
// postconditions: stock, director, title, and release year
// -------------------------------------------------------------------------
Drama::Drama(const string& director, const string& title, const int& year) : Movie(Drama::TYPE) 
{
    this->director = director;
    this->title = title;
    releaseYear = year;
}

// ---------------------operator<--------------------------------
// operator<: overload the < operator
// preconditions: none
// postconditions: checks if lhs is < rhs
// -------------------------------------------------------------------------
bool Drama::operator<(const Movie &movie)const 
{
    try 
    {
        const Drama& other = static_cast<const Drama&>(movie);
        return director < other.director && title < other.title;
    } 
    catch (const bad_cast& e) 
    {
        return Movie::operator<(movie);
    }
    return false;
}
     
// ---------------------getHashKey--------------------------------
// getHashKey: gets the hash key
// preconditions: none
// postconditions: shcecks if hashkey is empty
// -------------------------------------------------------------------------
string Drama::getHashKey() 
{
    if (hashKey.empty()) 
    {
        hashKey = director + " " + title;
    }
    return hashKey;
}

// ---------------------setData--------------------------------
// setData: sets the data 
// preconditions: none
// postconditions: sets data from the file
// -------------------------------------------------------------------------
istream& Drama::setData(istream &stream)
{
    Movie::setData(stream);
    string temp;
    getline(stream, temp, ',');
    releaseYear = stoi(temp);
    return stream;
}

// ---------------------toOutput--------------------------------
// toOuput: overlaod the output 
// preconditions: none
// postconditions: displays the ouput properly
// -------------------------------------------------------------------------
ostream& Drama::toOutput(ostream& output) const 
{
    Movie::toOutput(output);
    output << ", " << releaseYear;
    return output;
}
