# cmake_minimum_required(VERSION <specify CMake version here>)
project(x86ToMips)

set(CMAKE_CXX_STANDARD 14)

add_executable(x86ToMips code/main.cpp code/util/fileUtil.cpp code/util/fileUtil.h code/util/stringUtil.h code/util/stringUtil.cpp)