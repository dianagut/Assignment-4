//
//  Movie.cpp
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#include <stdio.h>
#include "Movie.h"
#include <iostream>
#include <string>
#include <sstream>
#include <istream>
using namespace std;

Movie::Movie(){
    movieType = NULL;
    director ="";
    title = "";
    releaseYear = 0;
    stock = 0;
}

void Movie::createMovie(string &data) {
    stringstream stream;
    stream << data;
    string temp;
    getline(stream, temp, ',');
    movieType = temp[0];
    getline(stream, temp, ',');
    stringstream (temp) >> stock;
    getline(stream, director, ',');
    getline(stream, title, ',');
    getline(stream, temp, ',');
    stringstream(temp) >> releaseYear;
}

bool Movie::increaseStock(int add){
    if(stock < 0)
        return false;
    stock += add;
    return true;
}

bool Movie::descreaseStock(int subtract){
    if(stock <= 0)
        return false;
    stock -= subtract;
    return true;
}

int Movie::getStock(){
    return stock;
}
