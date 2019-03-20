//
// Created by polina on 05.03.19.
//

#include <iostream>
#include <cmath>
#include "hash_lib.h"

#define fail -1
#define success 0
#define bigger 'b'
#define smaller 's'
#define minSize 10

unsigned short int Hash_table::setHashParam(unsigned int size, unsigned short int param) {
    static unsigned short int i;
    do {
        if (param == size) {
            return 1;
        }
        for (i = param; i > 1; i--) {
            if (size % i == 0 && param % i == 0) {
                if (i != 1) {
                    break;
                }
            }
        }
        param++;
    } while (i != 1);
    param--;
    return param;
}

Hash_table::Hash_table(unsigned int size, unsigned short int hashParam) {
    this->table = new Table_entry[size];
    this->size = size;
    this->count = 0;
    this->hashParam = setHashParam(size, hashParam);
}

unsigned int Hash_table::hash1(unsigned int &key) {
    return (key % size);
}

unsigned int Hash_table::hash2(unsigned int &key) {
    return (key + hashParam) % size;
}

Table_entry *Hash_table::searchEntry(Rec &rec) {
    long entryNumber = search(rec);
    if (entryNumber != fail) {
        return &table[entryNumber];
    } else {
        unsigned int hashValue = hash1(rec.key);
        if (table[hashValue].status == 0 || table[hashValue].status == 2) {
            return &table[hashValue];
        } else {
            while (table[hashValue].status == 1) {
                hashValue = hash2(hashValue);
            }
            return &table[hashValue];
        }
    }
}

long Hash_table::search(Rec &rec) {
    unsigned int hashValue = hash1(rec.key);
    if (table[hashValue].status == 0) {
        return fail;
    } else if (table[hashValue].status == 1 && table[hashValue].rec.key == rec.key) {
        return (hashValue);
    } else {
        while (table[hashValue].status != 0) {
            hashValue = hash2(hashValue);
            if (table[hashValue].status == 1 && table[hashValue].rec.key == rec.key) {
                return (hashValue);
            }
        }
    }
    return fail;
}

short Hash_table::add(Rec &rec) {
    if ((float) count / (float) size > full) {
        extend(bigger);
    }
    Table_entry *addPlace = searchEntry(rec);
    if (addPlace->status == 1) {
        return fail;
    } else {
        addPlace->status = 1;
        addPlace->rec.key = rec.key;
        addPlace->rec.value = rec.value;
        count++;
        return success;
    }
}

short Hash_table::del(Rec &rec) {
    long hashValue = search(rec);
    if (hashValue != fail && table[hashValue].rec.value == rec.value) {
        table[hashValue].status = 2;
        count--;
        if (size > minSize && (float) count / (float) size < empty) {
            extend(smaller);
        }
        return success;
    }
    return fail;
}

void Hash_table::extend(char c) {
    unsigned int newSize = size;
    c == bigger ? newSize *= 2 : newSize /= 2;
    Table_entry *tmpTable = table;
    auto *newTable = new Table_entry[newSize];
    this->table = newTable;
    std::swap(this->size, newSize);
    this->count = 0;
    this->hashParam = setHashParam(size, hashParam);
    for (unsigned int i = 0; i < newSize; i++) {
        if (tmpTable[i].status == 1) {
            add(tmpTable[i].rec);
        }
    }
    delete[] tmpTable;
}

void Hash_table::pringAll() {
    std::cout << "Параметр функции хеш: " << hashParam << std::endl;
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
