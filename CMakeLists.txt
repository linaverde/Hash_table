cmake_minimum_required(VERSION 3.12)
project(hash)

set(CMAKE_CXX_STANDARD 14)

add_executable(hash main.cpp lib_dir/hash_lib.cpp lib_dir/hash_lib.h)

add_executable(test test_dir/testMain.cpp test_dir/test.cpp lib_dir/hash_lib.cpp lib_dir/hash_lib.h)