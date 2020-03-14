// ------------------------------------------------StringUtils.cpp -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: String Utilities implementation class
// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------

#include "StringUtils.h"
using namespace std;

// ---------------------ltrim--------------------------------
// ltrim: removes leading spaces in a string
// preconditions: Must have two strings
// postconditions: Will return new string with removed spaces
// -------------------------------------------------------------------------
string& StringUtils::ltrim(string& str, const string& chars)
{
    str.erase(0, str.find_first_not_of(chars)); // removes leading spaces
    return str;
}
 
// ---------------------rtrim--------------------------------
// rtrim: removes trailing spaces in a string
// preconditions: Must have two strings
// postconditions: Will return new string with removed spaces
// -------------------------------------------------------------------------
string& StringUtils::rtrim(string& str, const string& chars )
{
    str.erase(str.find_last_not_of(chars) + 1); // removes trailing spaces
    return str;
}
 
// ---------------------trim--------------------------------
// trim: combines two trimed strings
// preconditions: Must have two strings
// postconditions: Will return combined string
// -------------------------------------------------------------------------
string& StringUtils::trim(string& str, const string& chars )
{
    return ltrim(rtrim(str, chars), chars); // combines trimed strings
}

// ---------------------split--------------------------------
// split: splits a string using an identifier of where to split it
// preconditions: Input a string and identifier
// postconditions: Will return a vector of the new split strings
// -------------------------------------------------------------------------
vector<string> StringUtils::split(const string& s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}
