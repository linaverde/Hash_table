//
// Created by polina on 05.03.19.
//

#include <catch2/catch.hpp>
#include <string>
#include <iostream>
#include "../lib_dir/hash_lib.h"

TEST_CASE("Base", "[hash]") {
    Hash_table MyTable(10);
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
    REQUIRE(MyTable.search(FalseRec) == -1);
    MyTable.del(MyRec);
    REQUIRE(MyTable.getCount() == 0);
    MyTable.del(FalseRec);
    REQUIRE(MyTable.getCount() == 0);
    REQUIRE(MyTable.getSize() == 10);
    MyTable.pringAll();
};

TEST_CASE("Extend", "[hash]") {
    Hash_table MyTable(10);
    Rec MyRec;
    MyRec.value = "Журнал";
    for (unsigned int i = 100000; i < 100100; i++){
        MyRec.key = i;
        MyTable.add(MyRec);
    }
    REQUIRE(MyTable.getCount() == 100);
    std::cout << "Размер таблицы: " << MyTable.getSize() << std::endl;
    MyTable.pringAll();
};