// ---------------------------------------------- StringUtils.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------


#ifndef StringUtils_h
#define StringUtils_h

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class StringUtils {
public:
    static std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ");
    static std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ");
    static std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ");

    static std::vector<std::string> split(const std::string& s, char delimiter);
};

#endif
