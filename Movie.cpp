// ------------------------------------------------ Movie.cpp -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// -------------------------------------------------------------------------------------------------------------------- // Notes on specifications, special algorithms, and assumptions. 
// -------------------------------------------------------------------------------------------------------------------- 

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

Movie::Movie(char type) {
    movieType = type;
    director = "";
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
<<<<<<< HEAD
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
                cout << "Movie type " << line[0] << " not recognized:\n";
                cout << "\t-> " << line << '\n';
=======
        switch (type[0]) {
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
>>>>>>> 888d2ed62f8022b0126b4d6233bc04ad21e0482e
        }
        if (answer) {
            answer->setData(iss);
        }
    }
    return answer;
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

void Movie::createMovie(string& data) {
    stringstream stream;
    stream << data;
    string temp;
    getline(stream, temp, ',');
    movieType = temp[0];
    getline(stream, temp, ',');
    stringstream(temp) >> stock;
    getline(stream, director, ',');
    getline(stream, title, ',');
    getline(stream, temp, ',');
    stringstream(temp) >> releaseYear;
}

bool Movie::increaseStock(int add) {
<<<<<<< HEAD
    if(stock < 0)
=======
    if (stock < 0)
>>>>>>> 888d2ed62f8022b0126b4d6233bc04ad21e0482e
        return false;
    stock += add;
    return true;
}

bool Movie::descreaseStock(int subtract) {
<<<<<<< HEAD
    if(stock <= 0)
=======
    if (stock <= 0)
>>>>>>> 888d2ed62f8022b0126b4d6233bc04ad21e0482e
        return false;
    stock -= subtract;
    return true;
}

<<<<<<< HEAD
bool Movie::operator<(const Movie &movie) const {
    return movieType < movie.movieType;
}

bool Movie::operator>(const Movie& movie) const {
    return !(*this < movie);
}

bool Movie::operator==(const Movie& movie) const {
    return (this->director == movie.director);// && this->title == movie.title && this->releaseYear == movie.releaseYear );
}

bool Movie::operator!=(const Movie& movie) const{
    return !(*this == movie);
}

std::ostream & Movie::toOutput(std::ostream & output) const {
=======
std::ostream& Movie::toOutput(std::ostream& output) const {
>>>>>>> 888d2ed62f8022b0126b4d6233bc04ad21e0482e
    output << movieType << ", " << stock << ", " << director << ", " << title;
    return output;
}

ostream& operator<<(ostream& output, const Movie& m) {
    return m.toOutput(output);
}
<<<<<<< HEAD
=======

std::string& Movie::ltrim(std::string& str, const std::string& chars)
{
    str.erase(0, str.find_first_not_of(chars)); 
    return str;
}

std::string& Movie::rtrim(std::string& str, const std::string& chars)
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

std::string& Movie::trim(std::string& str, const std::string& chars)
{
    return ltrim(rtrim(str, chars), chars);
}
>>>>>>> 888d2ed62f8022b0126b4d6233bc04ad21e0482e
