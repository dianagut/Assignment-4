// ---------------------------------------------- StringUtils.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will implement StringUtils
// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------

#ifndef StringUtils_h
#define StringUtils_h

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class StringUtils {
public:
    static string& ltrim(string& str, const string& chars = "\t\n\v\f\r ");//removes leading spaces in a string
    static string& rtrim(string& str, const string& chars = "\t\n\v\f\r ");//removes trailing spaces in a string
    static string& trim(string& str, const string& chars = "\t\n\v\f\r ");//combines two trimed strings

    static vector<string> split(const string& s, char delimiter);//splits a string using an identifier of where to split it
};

#endif
