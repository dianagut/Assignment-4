//
//  StringUtils.hpp
//  Movies
//
//  Created by Francisco Sanchez on 3/9/20.
//  Copyright © 2020 Francisco Sanchez. All rights reserved.
//

#ifndef StringUtils_hpp
#define StringUtils_hpp

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
#endif /* StringUtils_hpp */
