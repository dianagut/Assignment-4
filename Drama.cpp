//
//  Drama.cpp
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Drama.h"

Drama::Drama() : Movie(Drama::TYPE) {
}
 
Drama::Drama(const string& director, const string& title, const int& year) : Movie(Drama::TYPE){
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
    return director + title;
}

std::istream& Drama::setData(std::istream &stream)
{
    Movie::setData(stream);
    std::string temp;
    getline(stream, temp, ',');
    releaseYear = std::stoi(temp);
    return stream;
}

std::ostream & Drama::toOutput(std::ostream &output) const {
    Movie::toOutput(output);
    output << ", " << releaseYear;
    return output;
}
