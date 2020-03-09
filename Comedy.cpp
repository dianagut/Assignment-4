// ------------------------------------------------Comedy.cpp -------------------------------------------------------
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
#include "Comedy.h"

Comedy::Comedy() : Movie(Comedy::TYPE) {
}

Comedy::Comedy(const string& director, const string& title, const int& year) : Movie(Comedy::TYPE) {
    this->director = director;
    this->title = title;
    releaseYear = year;
}

std::istream& Comedy::setData(std::istream& stream)
{
    Movie::setData(stream);
    std::string temp;
    getline(stream, temp, ',');
    releaseYear = std::stoi(temp);
    return stream;
}

bool Comedy::operator<(const Movie& movie)const {
    const Comedy& comedyCast = static_cast<const Comedy&>(movie);

    if (this->director < comedyCast.director && this->title < comedyCast.title && this->releaseYear < comedyCast.releaseYear)
        return true;
    return false;
}

bool Comedy::operator>(const Movie& movie)const {
    return !(*this < movie);
}

bool Comedy::operator==(const Movie& movie)const {
    const Comedy& comedyCast = static_cast<const Comedy&>(movie);

    if (this->director == comedyCast.director && this->title == comedyCast.title && this->releaseYear == comedyCast.releaseYear)
        return true;
    return false;
}

bool Comedy::operator!=(const Movie& movie)const {
    return !(*this == movie);
}

std::ostream& Comedy::toOutput(std::ostream& output) const {
    Movie::toOutput(output);
    output << ", " << releaseYear;
    return output;
}
