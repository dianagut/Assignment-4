// ----------------------------------------------- HashTable.h ----------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will implement the HashTable class
// --------------------------------------------------------------------------------------------------------------------
// Notes: This class uses a template
// --------------------------------------------------------------------------------------------------------------------

#ifndef HashTable_hpp
#define HashTable_hpp

#include <string>
#include "Movie.h"
#include "HashNode.h"
using namespace std;

//template
template <typename Key, typename Val, typename Function = KeyHash<Key> >

class HashTable 
{

public:
// ---------------------constructor--------------------------------
// constructor: constructor
// preconditions: none
// postconditions: table
// ------------------------------------------------------------------------
    HashTable() 
    {
        table = new HashNode<Key, Val> * [TABLE_SIZE]();
    }

// ---------------------destructor--------------------------------
// destructor: deallocates memory
// preconditions: none
// postconditions: deallocates memory when out of scope
// ------------------------------------------------------------------------
    ~HashTable() 
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            HashNode<Key, Val>* item = table[i];
            while (item)
            {
                HashNode<Key, Val>* p = item;
                item = item->getNext();
                delete p;
            }
            table[i] = NULL;
        }
        delete[] table;
    }

// ---------------------insert--------------------------------
// insert:inserts in table
// preconditions: none
// postconditions: inserts the key and value
// ------------------------------------------------------------------------
    void insert(const Key& k, const Val& v) 
    {
        int hashVal = function(k);
        HashNode<Key, Val>* p = NULL;
        HashNode<Key, Val>* item = table[hashVal];

        while (item && item->getKey() != k) 
        {
            p = item;
            item = item->getNext();
        }

        if (!item) 
        {
            item = new HashNode<Key, Val>(k, v);
            if (!p) 
            {
                table[hashVal] = item;
            }
            else 
            {
                p->setNext(item);
            }
        }
        else 
        {
            item->setVal(v);
        }
    }

// ---------------------retrieve--------------------------------
// retrieve: retreives item
// preconditions: none
// postconditions: returns true if item matches
// ------------------------------------------------------------------------
    bool retrieve(const Key& k, Val& v) 
    { 
        int hashVal = function(k);
        HashNode<Key, Val>* item = table[hashVal];

        while (item) 
        {
            if (item->getKey() == k) 
            {
                v = item->getVal();
                return true;
            }
            item = item->getNext();
        }
        return false;
    }

 // ---------------------removeItem--------------------------------
// removeItem: removes given item
// preconditions: takes in k
// postconditions: finds the item and deletes
// ------------------------------------------------------------------------
    void removeItem(const Key& k) 
    {
        int hashVal = function(k);
        HashNode<Key, Val>* p = NULL;
        HashNode<Key, Val>* item = table[hashVal];

        while (item && item->getKey() != k) 
        {
            p = item;
            item = item->getNext();
        }

        if (!item) 
        {
            return;
        }
        else 
        {
            if (!p) 
            {
                table[hashVal] = item->getNext();
            }
            else 
            {
                p->setNext(item->getNext());
            }
            delete item;
        }
    }

// ---------------------getKeys--------------------------------
// getKeys: getter for keys
// preconditions: none
// postconditions: returns index
// ------------------------------------------------------------------------
    int getKeys(Key keys[]) const 
    {
        int index = 0;
        for (int i = 0; i < TABLE_SIZE; i++) 
        {
            HashNode<Key, Val>* item = table[i];
            while (item != NULL) {
                keys[index++] = item->getKey();
                item = item->getNext();
            }
        }
        return index;
    }

private:

    HashNode<Key, Val>** table;
    Function function;
};

//struct for moviehash
struct MovieHash 
{
    int operator()(const string& k) const
    {
        return hash<string>()(k) % TABLE_SIZE;
    }
};

#endif
