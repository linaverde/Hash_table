//
// Created by polina on 05.03.19.
//

#include <catch2/catch.hpp>
#include <string>
#include "../lib_dir/hash_lib.h"

TEST_CASE("Creating", "[hash]"){
    Hash_table MyTable(10);
    MyTable.add(100123, "Мурзилка");
    MyTable.pringAll();
};