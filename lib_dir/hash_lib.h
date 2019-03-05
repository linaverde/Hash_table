//
// Created by polina on 05.03.19.
//

#ifndef HASH_HASH_LIB_H
#define HASH_HASH_LIB_H

#include <string>

struct Table_entry {
    std::string value;
    unsigned int key;
    unsigned short int status;
};

class Hash_table {
    const float full = 0.75;
    const unsigned short int hashParam = 3;
    unsigned int count;
    unsigned int size;

    Table_entry *table;

    unsigned int hash1(unsigned int key);

    unsigned int hash2(unsigned int key);

    void extend();

public:
    Hash_table(unsigned int size);

    void add(unsigned int key, std::string value);

    void del(unsigned int key, std::string value);

    long search(unsigned int index, std::string value);

    void pringAll();

    void printForKey(unsigned int key);

    unsigned int getCount();

    unsigned int getSize();
};

#endif //HASH_HASH_LIB_H
