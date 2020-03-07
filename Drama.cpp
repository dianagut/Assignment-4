//
//  Drama.cpp
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Drama.h"

Drama::Drama(){
    director = "";
    title = "";
    releaseYear = 0;
}
 
Drama::Drama(const string& director, const string& title, const int& year){
    this->director = director;
    this->title = title;
    releaseYear = year;
}

bool Drama::operator<(const Movie &movie)const{
    const Drama& dramaCast = static_cast<const Drama&>(movie);
    
    if(this->director < dramaCast.director && this->title < dramaCast.title && this-> releaseYear < dramaCast.releaseYear)
        return true;
    return false;
}

bool Drama::operator>(const Movie& movie)const{
    return !(*this < movie);
}

bool Drama::operator==(const Movie& movie)const{
     const Drama& dramaCast = static_cast<const Drama&>(movie);
    
    if(this->director == dramaCast.director && this->title == dramaCast.title && this-> releaseYear == dramaCast.releaseYear)
        return true;
    return false;
}

bool Drama::operator!=(const Movie& movie)const{
    return !(*this == movie);
}
