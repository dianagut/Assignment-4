//
//  Comedy.cpp
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Comedy.h"

Comedy::Comedy(){
    director = "";
    title = "";
    releaseYear = 0;
}

Comedy::Comedy(const string& director, const string& title, const int& year){
    this->director = director;
    this->title = title;
    releaseYear = year;
}

bool Comedy::operator<(const Movie &movie)const{
    const Comedy& comedyCast = static_cast<const Comedy&>(movie);
    
    if(this->director < comedyCast.director && this->title < comedyCast.title && this-> releaseYear < comedyCast.releaseYear)
        return true;
    return false;
}

bool Comedy::operator>(const Movie& movie)const{
    return !(*this < movie);
}

bool Comedy::operator==(const Movie& movie)const{
     const Comedy& comedyCast = static_cast<const Comedy&>(movie);
    
    if(this->director == comedyCast.director && this->title == comedyCast.title && this-> releaseYear == comedyCast.releaseYear)
        return true;
    return false;
}

bool Comedy::operator!=(const Movie& movie)const{
    return !(*this == movie);
}
