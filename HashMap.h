// ----------------------------------------------- HashMap.h ----------------------------------------------------------
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will implement the HashMap class
// --------------------------------------------------------------------------------------------------------------------
// Notes: This class uses a template
// --------------------------------------------------------------------------------------------------------------------

#ifndef HashMap_hpp
#define HashMap_hpp

#include <string>
#include "Movie.h"
#include "HashNode.h"
using namespace std;

// Hash map class template
template <typename K, typename V, typename F = KeyHash<K> >
class HashMap {
public:
    HashMap() {
        // construct zero initialized hash table of size
        table = new HashNode<K, V> *[TABLE_SIZE]();
    }

    ~HashMap() {
        // destroy all buckets one by one
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            HashNode<K, V> *entry = table[i];
            while (entry) {
                HashNode<K, V> *prev = entry;
                entry = entry->getNext();
                delete prev;
            }
            table[i] = NULL;
        }
        // destroy the hash table
        delete [] table;
    }

    bool get(const K &key, V &value) { //
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *entry = table[hashValue];

        while (entry) {
            if (entry->getKey() == key) {
                value = entry->getValue();
                return true;
            }
            entry = entry->getNext();
        }
        return false;
    }

    void put(const K &key, const V &value) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = NULL;
        HashNode<K, V> *entry = table[hashValue];

        while (entry && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (!entry) {
            entry = new HashNode<K, V>(key, value);
            if (!prev) {
                // insert as first bucket
                table[hashValue] = entry;
            } else {
                prev->setNext(entry);
            }
        } else {
            // just update the value
            entry->setValue(value);
        }
    }

    void remove(const K &key) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = NULL;
        HashNode<K, V> *entry = table[hashValue];

        while (entry && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (!entry) {
            // key not found
            return;
        }
        else {
            if (!prev) {
                // remove first bucket of the list
                table[hashValue] = entry->getNext();
            } else {
                prev->setNext(entry->getNext());
            }
            delete entry;
        }
    }

    int getKeys(K keys[]) const {
        int index = 0;
        for(int i = 0; i < TABLE_SIZE; i++) {
            HashNode<K, V> *entry = table[i];
            while(entry != NULL) {
                keys[index++]= entry->getKey();
                entry = entry->getNext();
            }
        }
        return index;
    }

private:
    // hash table
    HashNode<K, V> **table;
    F hashFunc;
};

struct MovieHash {
    unsigned long operator()(const string& k) const
    {
        return hash<string>()(k) % TABLE_SIZE;
    }
};

#endif
