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

const int TABLE_SIZE = 25;

template <typename Key, typename Val>
class HashNode 
{
public:
    HashNode(const Key& k, const Val& v) : //constructor
        k(k), v(v), next(NULL) {
    }

    Key getKey() const 
    { 
        return k;
    }

    Val getValue() const 
    { 
        return v;
    }

    void setValue(Val v) 
    { 
        HashNode::v = v;
    }

    HashNode* getNext() const 
    { 
        return next;
    }

    void setNext(HashNode* next) 
    {
        HashNode::next = next;
    }

private:

    Key k;
    Val v;
    HashNode* next;
};

// Default hash function class
template <typename Key>
struct KeyHash 
{
    int operator()(const Key& k) const
    {
        return reinterpret_cast<int>(k) % TABLE_SIZE;
    }
};

#endif /* HashNode_hpp */
