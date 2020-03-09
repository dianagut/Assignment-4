// ------------------------------------------------Classics.cpp -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// -------------------------------------------------------------------------------------------------------------------- // Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <typeinfo>
#include "Classics.h"

Classics::Classics() : Movie(Classics::TYPE) {
    majorActor = "";
    month = 0;
}

Classics::Classics(const string& director, const string& title, const string& majorActor, const int& year) : Movie(Classics::TYPE) {
    this->director = director;
    this->title = title;
    this->majorActor = majorActor;
    releaseYear = year;
}

std::string Classics::getHashKey() {
    return std::to_string(month) + std::to_string(releaseYear) + majorActor;
}

bool Classics::operator<(const Movie &movie)const {
    try {
        const Classics& other = static_cast<const Classics&>(movie);
        return month < other.month && releaseYear < other.releaseYear && majorActor < other.majorActor;
    } catch (const std::bad_cast& e) {
        return Movie::operator<(movie);
    }
    return false;
}

std::istream& Classics::setData(std::istream& stream)
{
    Movie::setData(stream);
    std::string temp;
    getline(stream, temp);
    vector<string> pieces = StringUtils::split(StringUtils::trim(temp), ' ');
    majorActor = pieces[0] + " " + pieces[1];
    month = std::stoi(pieces[2]);
    releaseYear = std::stoi(pieces[3]);
    return stream;
}

bool Classics::operator==(const Movie& movie) const {
    bool equals = Movie::operator==(movie);
    try {
        const Classics& classicsCast = static_cast<const Classics&>(movie);
        equals &= majorActor == classicsCast.majorActor;
    } catch (const std::bad_cast& e) {
        return equals;
    }
    return equals
}

std::ostream& Classics::toOutput(std::ostream& output) const {
    Movie::toOutput(output);
    output << ", " << majorActor << ", " << month << " " << releaseYear;
    return output;
}
