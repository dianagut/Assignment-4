// ----------------------------------------------- HashMap.h ----------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will implement the HashMap class
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
template <typename Key, typename Val, typename F = KeyHash<Key> >
class HashTable 
{
public:
    HashTable() 
    {
        table = new HashNode<Key, Val> * [TABLE_SIZE]();
    }

    ~HashTable() 
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            HashNode<Key, Val>* item = table[i];
            while (item)
            {
                HashNode<Key, Val>* prev = item;
                item = item->getNext();
                delete prev;
            }
            table[i] = NULL;
        }
        delete[] table;
    }

    void insert(const Key& k, const Val& v) 
    {
        int hashVal = function(k);
        HashNode<Key, Val>* prev = NULL;
        HashNode<Key, Val>* item = table[hashVal];

        while (item && item->getKey() != k) 
        {
            prev = item;
            item = item->getNext();
        }

        if (!item) 
        {
            item = new HashNode<Key, Val>(k, v);
            if (!prev) 
            {
                table[hashVal] = item;
            }
            else 
            {
                prev->setNext(item);
            }
        }
        else 
        {
            item->setValue(v);
        }
    }

    bool retrieve(const Key& k, Val& v) 
    { 
        int hashVal = function(k);
        HashNode<Key, Val>* item = table[hashVal];

        while (item) 
        {
            if (item->getKey() == k) 
            {
                v = item->getValue();
                return true;
            }
            item = item->getNext();
        }
        return false;
    }

    void removeItem(const Key& k) 
    {
        int hashVal = function(k);
        HashNode<Key, Val>* prev = NULL;
        HashNode<Key, Val>* item = table[hashVal];

        while (item && item->getKey() != k) {
            prev = item;
            item = item->getNext();
        }

        if (!item) {
            return;
        }
        else {
            if (!prev) {
                table[hashVal] = item->getNext();
            }
            else {
                prev->setNext(item->getNext());
            }
            delete item;
        }
    }

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
    F function;
};

struct MovieHash 
{
    int operator()(const string& k) const
    {
        return hash<string>()(k) % TABLE_SIZE;
    }
};

#endif