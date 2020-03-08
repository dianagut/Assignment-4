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
#include "Drama.h"
#include "Comedy.h"
#include "Classics.h"
using namespace std;

Movie::Movie(char type){
    movieType = type;
    director ="";
    title = "";
    releaseYear = 0;
    stock = 0;
}


Movie* Movie::fromLine(string line)
{
    Movie* answer = NULL;
    if (line.length() > 0) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;
        switch(type[0]) {
            case 'D':
                answer = new Drama();
                break;
            case 'C':
                answer = new Classics();
                break;
            case 'F':
                answer = new Comedy();
                break;
            default:
                cout << "Movie type " << line[0] << " not recognized";
        }
        if (answer) {
            answer->setData(iss);
        }
    }
    return answer;
}

std::istream& Movie::setData(std::istream &stream)
{
    std::string temp;
    getline(stream, temp, ',');
    stock = std::stoi(temp);
    getline(stream, director, ',');
    getline(stream, title, ',');
    return stream;
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

std::ostream & Movie::toOutput(std::ostream & output) const {
    output << movieType << ", " << stock << ", " << director << ", " << title;
    return output;
}

ostream& operator<<(ostream& output, const Movie& m) {
    return m.toOutput(output);
}

std::string& Movie::ltrim(std::string& str, const std::string& chars)
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}
 
std::string& Movie::rtrim(std::string& str, const std::string& chars )
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}
 
std::string& Movie::trim(std::string& str, const std::string& chars )
{
    return ltrim(rtrim(str, chars), chars);
}
