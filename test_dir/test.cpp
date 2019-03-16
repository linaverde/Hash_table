//
// Created by polina on 05.03.19.
//

#include <catch2/catch.hpp>
#include <string>
#include <iostream>
#include "../lib_dir/hash_lib.h"

#define fail -1
#define success 0

TEST_CASE("Base", "[hash]") {
    Hash_table MyTable(10, 2);
    Rec MyRec;
    MyRec.key = 100123;
    MyRec.value = "Мурзилка";
    Rec FalseRec;
    FalseRec.key = 100001;
    FalseRec.value = "Журнал";
    MyTable.add(MyRec);
    MyTable.pringAll();
    REQUIRE(MyTable.getCount() == 1);
    REQUIRE(MyTable.getSize() == 10);
    REQUIRE(MyTable.search(MyRec) == 3);
    REQUIRE(MyTable.search(FalseRec) == fail);
    MyTable.del(MyRec);
    REQUIRE(MyTable.getCount() == 0);
    MyTable.del(FalseRec);
    REQUIRE(MyTable.getCount() == 0);
    REQUIRE(MyTable.getSize() == 10);
    MyTable.pringAll();
};

TEST_CASE("Index", "[hash]") {
    Hash_table MyTable(10, 10);
    Rec rec1, rec2, rec3;
    rec1.key = 1;
    rec1.value = "Журнал";
    rec2 = rec1;
    rec3 = rec1;
    rec3.key = 11;
    REQUIRE(MyTable.add(rec1) == success);
    REQUIRE(MyTable.add(rec1) == fail);
    REQUIRE(MyTable.add(rec2) == fail);
    REQUIRE(MyTable.add(rec3) == success);
    MyTable.pringAll();
    REQUIRE(MyTable.del(rec1) == success);
    rec2.key = 111;
    REQUIRE(MyTable.add(rec3) == fail);
    REQUIRE(MyTable.add(rec2) == success);
    MyTable.pringAll();
}

TEST_CASE("Extend", "[hash]") {
    Hash_table MyTable(10, 3);
    std::cout << "Размер таблицы: " << MyTable.getSize() << std::endl;
    MyTable.pringAll();
    Rec MyRec;
    MyRec.value = "Журнал";
    //добавление элементов
    for (unsigned int i = 100000; i < 100100; i++) {
        MyRec.key = i;
        MyTable.add(MyRec);
    }
    REQUIRE(MyTable.getCount() == 100);
    std::cout << "Размер таблицы: " << MyTable.getSize() << std::endl;
    MyTable.pringAll();
    //удаление элементов
    for (unsigned int i = 100000; i < 100100; i++) {
        MyRec.key = i;
        MyTable.del(MyRec);
    }
    REQUIRE(MyTable.getCount() == 0);
    std::cout << "Размер таблицы: " << MyTable.getSize() << std::endl;
    MyTable.pringAll();
};