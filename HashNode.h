// ------------------------------------------------HashNode.h -------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified: March 14, 2020
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

//template
template <typename Key, typename Val>
class HashNode 
{
public:
// ---------------------constructor--------------------------------
// constructor: constructor
// preconditions: none
// postconditions: sets k, v, and next
// ------------------------------------------------------------------------
    HashNode(const Key& k, const Val& v) : 
        k(k), v(v), next(NULL) {
    }

 // ---------------------getkey--------------------------------
// getKey: getter for key
// preconditions: none
// postconditions: gets the key
// ------------------------------------------------------------------------
    Key getKey() const 
    { 
        return k;
    }

// --------------------getValue--------------------------------
// getValue: getter for the value
// preconditions: none
// postconditions: gets the value
// ------------------------------------------------------------------------
    Val getVal() const 
    { 
        return v;
    }

// ---------------------setValue--------------------------------
// setValue: setter for the value
// preconditions: none
// postconditions: sets the value
// ------------------------------------------------------------------------
    void setVal(Val v) 
    { 
        HashNode::v = v;
    }
// ---------------------getNext--------------------------------
// getNext: getter for next
// preconditions: none
// postconditions: gets next 
// ------------------------------------------------------------------------
    HashNode* getNext() const 
    { 
        return next;
    }
// ---------------------setNext--------------------------------
// setNext: setter for next
// preconditions: none
// postconditions: sets the next
// ------------------------------------------------------------------------
    void setNext(HashNode* next) 
    {
        HashNode::next = next;
    }

private:

    Key k;
    Val v;
    HashNode* next;
};

//struct for keyHash
template <typename Key>
struct KeyHash 
{
    int operator()(const Key& k) const
    {
        return reinterpret_cast<int>(k) % TABLE_SIZE;
    }
};

#endif /* HashNode_hpp */
