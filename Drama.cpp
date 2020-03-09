// ------------------------------------------------Drama.cpp -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions. 
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

bool Drama::operator<(const Movie &movie)const {
    try {
        const Drama& other = static_cast<const Drama&>(movie);
        return director < other.director && title < other.title;
    } catch (const std::bad_cast& e) {
        return Movie::operator<(movie);
    }
    return false;
}
     
std::string Drama::getHashKey() {
    if (hashKey.empty()) {
        hashKey = director + " " + title;
            }
    return hashKey;
}

std::istream& Drama::setData(std::istream &stream)
{
    Movie::setData(stream);
    std::string temp;
    getline(stream, temp, ',');
    releaseYear = std::stoi(temp);
    return stream;
}

std::ostream& Drama::toOutput(std::ostream& output) const {
    Movie::toOutput(output);
    output << ", " << releaseYear;
    return output;
}
