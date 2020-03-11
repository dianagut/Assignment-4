// ------------------------------------------------StringUtils.cpp -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose:
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#include "StringUtils.h"

std::string& StringUtils::ltrim(std::string& str, const std::string& chars)
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}
 
std::string& StringUtils::rtrim(std::string& str, const std::string& chars )
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}
 
std::string& StringUtils::trim(std::string& str, const std::string& chars )
{
    return ltrim(rtrim(str, chars), chars);
}

std::vector<std::string> StringUtils::split(const std::string& s, char delimiter)
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
