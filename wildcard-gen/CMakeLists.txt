cmake_minimum_required(VERSION 3.10)
project(wildcard)

set(CMAKE_CXX_STANDARD 11)

add_executable(wildcard main.cpp wildcardgen.h)
add_executable(wildcard-test wildcardgen.h test.cpp)