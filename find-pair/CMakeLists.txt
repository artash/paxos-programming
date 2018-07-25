cmake_minimum_required(VERSION 3.10)
project(find-pair)

set(CMAKE_CXX_STANDARD 11)

add_executable(find-pair giftcards.cpp giftcards.h main.cpp)

add_executable(find-pair-test test.cpp giftcards.cpp giftcards.h catch.h)