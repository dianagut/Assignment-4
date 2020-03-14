
// ------------------------------------------------HashNode.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will implement the HashNode class
// --------------------------------------------------------------------------------------------------------------------
// Notes: This class uses a template
// -------------------------------------------------------------------------------------------------------------------- 

#ifndef HashNode_hpp
#define HashNode_hpp

#include <string>
#include "Movie.h"

const int TABLE_SIZE = 15;

template <typename K, typename V>
class HashNode {
public:
    HashNode(const K &key, const V &value) : //constructor
    key(key), value(value), next(NULL) {
    }

    K getKey() const { //key getter
        return key;
    }

    V getValue() const { //value getter
        return value;
    }

    void setValue(V value) { //value setter
        HashNode::value = value;
    }

    HashNode *getNext() const { //next getter
        return next;
    }

    void setNext(HashNode *next) {// next setter
        HashNode::next = next;
    }

private:
    // key-value pair
    K key;
    V value;
    // next bucket with the same key
    HashNode *next;
};

// Default hash function class
template <typename K>
struct KeyHash {
    unsigned long operator()(const K& key) const
    {
        return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
    }
};

#endif /* HashNode_hpp */
