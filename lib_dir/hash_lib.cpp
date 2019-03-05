//
// Created by polina on 05.03.19.
//

#include <iostream>
#include "hash_lib.h"

#define noEntry -1

Hash_table::Hash_table(unsigned int size) {
    table = new Table_entry[size];
    this->size = size;
    this->count = 0;
    for (int i = 0; i < size; i++) {
        table[i].status = 0;
    }
}

unsigned int Hash_table::hash1(unsigned int key) {
    return (key % size);
}

unsigned int Hash_table::hash2(unsigned int key) {
    return (key + hashParam);
}

long Hash_table::search(unsigned int key, std::string value) {
    unsigned int hashValue = hash1(key);
    if (table[hashValue].status == 0) {
        return noEntry;
    } else {
        while (table[hashValue].status != 0 && table[hashValue].key != key && hash2(hashValue) < size) {
            hashValue = hash2(hashValue);
        }
        if (hash2(hashValue) >= size) {
            return noEntry;
        }
        return (hashValue);
    }
}

void Hash_table::add(unsigned int key, std::string value) {
    unsigned int hashValue = hash1(key);
    if (table[hashValue].status == 0 || table[hashValue].status == 2) {
        table[hashValue].status = 1;
        table[hashValue].key = key;
        table[hashValue].value = value;
        count++;
    } else {
        while (table[hashValue].status == 1 && hash2(hashValue) < size) {
            hashValue = hash2(hashValue);
        }
        if (hashValue < size) {
            table[hashValue].status = 1;
            table[hashValue].key = key;
            table[hashValue].value = value;
            count++;
        } else {
            extend();
            add(key, value);
        }
    }
}

void Hash_table::del(unsigned int key, std::string value) {
    long hashValue = search(key, value);
    if (hashValue > -1) {
        table[hashValue].status = 2;
        count--;
    }
}

void Hash_table::extend() {
    unsigned int newSize = size * 2;
    Table_entry *tmpTable = table;
    Table_entry *newTable = new Table_entry[newSize];
    this->table = newTable;
    for (unsigned int i = 0; i < newSize; i++) {
        table[i].status = 0;
    }
    for (unsigned int i = 0; i < size; i++) {
        if (table[i].status == 1) {
            add(table[i].key, table[i].value);
        }
    }
    this->size = newSize;
}

void Hash_table::pringAll() {
    for (unsigned int i = 0; i < size; i++){
        if (table[i].status == 1){
            std:: cout << i << '\t' << table[i].key << '\t' << table[i].value << std::endl;
        }
    }
}

unsigned int Hash_table::getCount() {
    return count;
}

unsigned int Hash_table::getSize() {
    return size;
}