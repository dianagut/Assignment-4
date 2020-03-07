//
//  Classics.cpp
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Classics.h"

Classics::Classics(){
    director = "";
    title = "";
    releaseYear = 0;
    majorActor = "";
}

Classics::Classics(const string& director, const string& title, const string& majorActor, const int& year){
    this->director = director;
    this->title = title;
    this->majorActor = majorActor;
    releaseYear = year;
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

