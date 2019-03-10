//
// Created by polina on 05.03.19.
//

#include <iostream>
#include "hash_lib.h"

#define noEntry -1

Hash_table::Hash_table(unsigned int size) {
    this->table = new Table_entry[size];
    this->size = size;
    this->count = 0;
}

unsigned int Hash_table::hash1(unsigned int key) {
    return (key % size);
}

unsigned int Hash_table::hash2(unsigned int key) {
    return (key + hashParam);
}

long Hash_table::search(Rec rec) {
    unsigned int hashValue = hash1(rec.key);
    if (table[hashValue].status == 0) {
        return noEntry;
    } else if (table[hashValue].status == 1 && table[hashValue].rec.key == rec.key) {
        return (hashValue);
    } else {
        while (table[hashValue].status != 0 && hash2(hashValue) < size) {
            hashValue = hash2(hashValue);
            if (table[hashValue].status == 1 && table[hashValue].rec.key == rec.key) {
                return (hashValue);
            }
        }
        if (hash2(hashValue) >= size || table[hashValue].status == 0) {
            return noEntry;
        }
    }
}

void Hash_table::add(Rec rec) {
    if ((float) count / (float) size > full) {
        extend();
    }
    unsigned int hashValue = hash1(rec.key);
    if (table[hashValue].status == 0 || table[hashValue].status == 2) {
        table[hashValue].status = 1;
        table[hashValue].rec.key = rec.key;
        table[hashValue].rec.value = rec.value;
        count++;
    } else {
        while (table[hashValue].status == 1 && hash2(hashValue) < size) {
            hashValue = hash2(hashValue);
        }
        if (hashValue < size) {
            table[hashValue].status = 1;
            table[hashValue].rec.key = rec.key;
            table[hashValue].rec.value = rec.value;
            count++;
        } else {
            extend();
            add(rec);
        }
    }
}

void Hash_table::del(Rec rec) {
    long hashValue = search(rec);
    if (hashValue > -1) {
        table[hashValue].status = 2;
        count--;
    }
}

void Hash_table::extend() {
    unsigned int newSize = size * 2;
    Table_entry *tmpTable = table;
    auto *newTable = new Table_entry[newSize];
    this->table = newTable;
    this->size = newSize;
    this->count = 0;
    for (unsigned int i = 0; i < size/2; i++) {
        if (tmpTable[i].status == 1) {
            add(tmpTable[i].rec);
        }
    }
}

void Hash_table::pringAll() {
    if (count > 0) {
        for (unsigned int i = 0; i < size; i++) {
            if (table[i].status == 1) {
                std::cout << i << '\t' << table[i].rec.key << '\t' << table[i].rec.value << std::endl;
            }
        }
    } else {
        std::cout << "Таблица пуста" << std::endl;
    }
    for (int i = 0; i < 15; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

unsigned int Hash_table::getCount() {
    return count;
}

unsigned int Hash_table::getSize() {
    return size;
}