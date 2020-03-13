// ------------------------------------------------Classics.cpp -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This file implements the classics class
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: the file will be formatted correctly
// --------------------------------------------------------------------------------------------------------------------

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <typeinfo>
#include "Classics.h"

using namespace std;

// ---------------------Constructor--------------------------------
// Constructor: default contructor 
// preconditions: none
// postconditions: sets month to 0 & major actor to empty string
// -------------------------------------------------------------------------
Classics::Classics() : Movie(Classics::TYPE) 
{
    majorActor = "";
    month = 0;
}

// ---------------------Constructor--------------------------------
// Constructor: overloaded contructor 
// preconditions: none
// postconditions: sets director, title, major actor, and release year
// -------------------------------------------------------------------------
Classics::Classics(const string& director, const string& title, const string& majorActor, const int& year) : Movie(Classics::TYPE) 
{
    this->director = director;
    this->title = title;
    this->majorActor = majorActor;
    releaseYear = year;
}

// ---------------------getHashKey--------------------------------
// getHashKey: inserts classic
// preconditions: none
// postconditions: if empty inserts movie
// -------------------------------------------------------------------------
string Classics::getHashKey() 
{
    if (hashKey.empty()) 
    {
        hashKey = to_string(month) + " " + to_string(releaseYear) + " " + majorActor;
    }
    return hashKey;
}

// ---------------------Operator<--------------------------------
// Operator<: overloaded < operator
// preconditions: takes in a movie
// postconditions: checks if lhs movie is < rhs
// -------------------------------------------------------------------------
bool Classics::operator<(const Movie &movie)const {
    try {
        const Classics& other = static_cast<const Classics&>(movie);
        return month < other.month && releaseYear < other.releaseYear && majorActor < other.majorActor;
    } catch (const bad_cast& e) {
        return Movie::operator<(movie);
    }
    return false;
}
        
// ---------------------Operator==--------------------------------
// Operator==: overloaded == operator
// preconditions: takes in a movie
// postconditions: checks if rhs movie is == lhs
// -------------------------------------------------------------------------
bool Classics::operator==(const Movie& movie) const
{
    bool equals = Movie::operator==(movie);
    try {
        const Classics& classicsCast = static_cast<const Classics&>(movie);
        equals &= majorActor == classicsCast.majorActor;
    } catch (const bad_cast& e) {
        return equals;
    }
    return equals;
}

// ---------------------setData--------------------------------
// setData: sets classic
// preconditions: none
// postconditions: sets data from isteam
// -------------------------------------------------------------------------
istream& Classics::setData(istream& stream)
{
    Movie::setData(stream);
    string temp;
    getline(stream, temp);
    vector<string> pieces = StringUtils::split(StringUtils::trim(temp), ' ');
    majorActor = pieces[0] + " " + pieces[1];
    month = stoi(pieces[2]);
    releaseYear = stoi(pieces[3]);
    return stream;
}

// ---------------------Ostream--------------------------------
// Osteram: overloaded output operator
// preconditions: none
// postconditions: displays in given format
// -------------------------------------------------------------------------
ostream& Classics::toOutput(ostream& output) const {
    Movie::toOutput(output);
    output << ", " << majorActor << ", " << month << " " << releaseYear;
    return output;
}
