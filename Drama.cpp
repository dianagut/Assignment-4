// ------------------------------------------------Drama.cpp -------------------------------------------------------
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
#include "Drama.h"

Drama::Drama() : Movie(Drama::TYPE) {
}

Drama::Drama(const string& director, const string& title, const int& year) : Movie(Drama::TYPE) {
    this->director = director;
    this->title = title;
    releaseYear = year;
}

std::istream& Drama::setData(std::istream& stream)
{
    Movie::setData(stream);
    std::string temp;
    getline(stream, temp, ',');
    releaseYear = std::stoi(temp);
    return stream;
}

bool Drama::operator<(const Movie& movie)const {
    const Drama& dramaCast = static_cast<const Drama&>(movie);

    if (this->director < dramaCast.director && this->title < dramaCast.title && this->releaseYear < dramaCast.releaseYear)
        return true;
    return false;
}

bool Drama::operator>(const Movie& movie)const {
    return !(*this < movie);
}

bool Drama::operator==(const Movie& movie)const {
    const Drama& dramaCast = static_cast<const Drama&>(movie);

    if (this->director == dramaCast.director && this->title == dramaCast.title && this->releaseYear == dramaCast.releaseYear)
        return true;
    return false;
}

bool Drama::operator!=(const Movie& movie)const {
    return !(*this == movie);
}

std::ostream& Drama::toOutput(std::ostream& output) const {
    Movie::toOutput(output);
    output << ", " << releaseYear;
    return output;
}
