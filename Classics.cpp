//
//  Classics.cpp
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Classics.h"

Classics::Classics() : Movie(Classics::TYPE){
    majorActor = "";
    month = 0;
}

Classics::Classics(const string& director, const string& title, const string& majorActor, const int& year) : Movie(Classics::TYPE){
    this->director = director;
    this->title = title;
    this->majorActor = majorActor;
    releaseYear = year;
}

std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

std::istream& Classics::setData(std::istream &stream)
{
    Movie::setData(stream);
    std::string temp ;
    getline(stream, temp);
    vector<string> pieces = split(trim(temp), ' ');
    majorActor = pieces[0] + " " + pieces[1];
    month = std::stoi(pieces[2]);
    releaseYear = std::stoi(pieces[3]);
    return stream;
}

bool Classics::operator<(const Movie &movie)const{
    const Classics& classicsCast = static_cast<const Classics&>(movie);
    
    if(this->director < classicsCast.director && this->title < classicsCast.title && this->majorActor < classicsCast.majorActor && this-> releaseYear < classicsCast.releaseYear)
        return true;
    return false;
}

bool Classics::operator>(const Movie& movie)const{
    return !(*this < movie);
}

bool Classics::operator==(const Movie& movie)const{
     const Classics& classicsCast = static_cast<const Classics&>(movie);
    
    if(this->director == classicsCast.director && this->title == classicsCast.title && this -> majorActor < classicsCast.majorActor && this-> releaseYear == classicsCast.releaseYear)
        return true;
    return false;
}

bool Classics::operator!=(const Movie& movie)const{
    return !(*this == movie);
}

std::ostream & Classics::toOutput(std::ostream &output) const {
    Movie::toOutput(output);
    output << ", " << month << " " << releaseYear;
    return output;
}
