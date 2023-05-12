cmake_minimum_required(VERSION 3.24)
project(test)

set(CMAKE_CXX_STANDARD 20)

add_executable(test Set.cpp Set.cpp Set.h ExtendedTest.cpp App.cpp SetIterator.cpp ShortTest.cpp)
