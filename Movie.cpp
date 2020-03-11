// ------------------------------------------------ Movie.cpp -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
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

Movie::Movie(char movieType, char mediaType) {
    this->movieType = movieType;
    director = "";
    title = "";
    releaseYear = 0;
    stock = 0;
    this->mediaType = mediaType;
}

std::istream& Movie::setData(std::istream& stream)
{
    std::string temp;
    getline(stream, temp, ',');
    stock = std::stoi(temp);
    getline(stream, temp, ',');
    director = StringUtils::trim(temp);
    getline(stream, temp, ',');
    title = StringUtils::trim(temp);
    return stream;
}

bool Movie::increaseStock(int add) {
    stock += add;
    return true;
}

bool Movie::descreaseStock(int subtract) {
    if (stock <= 0) {
        stock = 0 ; // this can't go below zero for any reason
        return false;
    }
    stock -= subtract;
    return true;
}

bool Movie::operator<(const Movie &movie) const {
    return movieType < movie.movieType;
}

bool Movie::operator>(const Movie& movie) const {
    return !(*this < movie);
}

bool Movie::operator==(const Movie& movie) const {
    return movieType == movie.movieType &&
    director == movie.director &&
    title == movie.title &&
    releaseYear == movie.releaseYear;
}

bool Movie::operator!=(const Movie& movie)const {
    return !(*this == movie);
}

std::ostream& Movie::toOutput(std::ostream& output) const {
    output << movieType << ", " << stock << ", " << director << ", " << title;
    return output;
}

ostream& operator<<(ostream& output, const Movie& movie) {
    return movie.toOutput(output);
}
