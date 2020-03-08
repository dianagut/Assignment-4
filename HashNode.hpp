//
//  HashNode.hpp
//  Movies
//
//  Created by Francisco Sanchez on 3/7/20.
//  Copyright © 2020 Francisco Sanchez. All rights reserved.
//

#ifndef HashNode_hpp
#define HashNode_hpp

#include <string>
#include "Movie.h"

const int TABLE_SIZE = 200;

class HashNode {
public:
    HashNode(const std::string &key, Movie * value) :
    key(key), value(value), next(NULL) {
    }

    std::string getKey() const {
        return key;
    }

    Movie* getValue() const {
        return value;
    }

    void setValue(Movie* value) {
        HashNode::value = value;
    }

    HashNode *getNext() const {
        return next;
    }

    void setNext(HashNode *next) {
        HashNode::next = next;
    }

private:
    // key-value pair
    std::string key;
    Movie* value;
    // next bucket with the same key
    HashNode *next;
};


template <typename K>
struct KeyHash {
    unsigned long operator()(const K& key) const
    {
        return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
    }
};

#endif /* HashNode_hpp */
