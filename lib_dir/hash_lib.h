//
// Created by polina on 05.03.19.
//

#ifndef HASH_HASH_LIB_H
#define HASH_HASH_LIB_H

#include <string>

struct Rec {
    std::string value;
    unsigned int key;
};

struct Table_entry {
    Rec rec;
    unsigned short int status = 0;
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

    void add(Rec rec);

    void del(Rec rec);

    long search(Rec rec);

    void pringAll();


    unsigned int getCount();

    unsigned int getSize();
};

#endif //HASH_HASH_LIB_H
