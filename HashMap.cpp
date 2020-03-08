//
//  HashMap.cpp
//  Movies
//
//  Created by Francisco Sanchez on 3/7/20.
//  Copyright © 2020 Francisco Sanchez. All rights reserved.
//

#include "HashMap.hpp"

HashMap::HashMap() {
    table = new HashNode *[TABLE_SIZE]();
}

HashMap::~HashMap() {
    // destroy all bucstd::stringets one by one
    for (int i = 0; i < TABLE_SIZE; ++i) {
        HashNode *entry = table[i];
        while (entry != NULL) {
            HashNode *prev = entry;
            entry = entry->getNext();
            delete prev;
        }
        table[i] = NULL;
    }
    // destroy the hash table
    delete [] table;
}

bool HashMap::get(const std::string &key, Movie* &value) {
    unsigned long hasValue = hashFunc(key);
    HashNode *entry = table[hasValue];

    while (entry != NULL) {
        if (entry->getKey() == key) {
            value = entry->getValue();
            return true;
        }
        entry = entry->getNext();
    }
    return false;
}

void HashMap::put(const std::string &key,  Movie* value) {
    unsigned long hasValue = hashFunc(key);
    HashNode *prev = NULL;
    HashNode *entry = table[hasValue];

    while (entry != NULL && entry->getKey() != key) {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == NULL) {
        entry = new HashNode(key, value);
        if (prev == NULL) {
            // insert as first bucstd::stringet
            table[hasValue] = entry;
        } else {
            prev->setNext(entry);
        }
    } else {
        // just update the value
        entry->setValue(value);
    }
}

void HashMap::remove(const std::string &key) {
    unsigned long hasValue = hashFunc(key);
    HashNode *prev = NULL;
    HashNode *entry = table[hasValue];

    while (entry != NULL && entry->getKey() != key) {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == NULL) {
        // key not found
        return;
    }
    else {
        if (prev == NULL) {
            // remove first bucstd::stringet of the list
            table[hasValue] = entry->getNext();
        } else {
            prev->setNext(entry->getNext());
        }
        delete entry;
    }
}
