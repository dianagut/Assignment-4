// ------------------------------------------------Comedy.cpp -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#include <typeinfo>
#include "Comedy.h"

Comedy::Comedy() : Movie(Comedy::TYPE) {
}

Comedy::Comedy(const string& director, const string& title, const int& year) : Movie(Comedy::TYPE) {
    this->director = director;
    this->title = title;
    releaseYear = year;
}

bool Comedy::operator<(const Movie &movie) const {
    try {
        const Comedy& other = static_cast<const Comedy&>(movie);
        return title < other.title && releaseYear < other.releaseYear;
    } catch (const std::bad_cast& e) {
        return Movie::operator<(movie);
    }
    return false;
}

std::string Comedy::getHashKey() {
    if (hashKey.empty()) {
        hashKey = title + " " + std::to_string(releaseYear);
    }
    return hashKey;
}

std::istream& Comedy::setData(std::istream &stream)
{
    Movie::setData(stream);
    std::string temp;
    getline(stream, temp, ',');
    releaseYear = std::stoi(temp);
    return stream;
}

std::ostream & Comedy::toOutput(std::ostream &output) const {
    Movie::toOutput(output);
    output << ", " << releaseYear;
    return output;
}
