cmake_minimum_required(VERSION 3.25)
project(BagOfPairs)

set(CMAKE_CXX_STANDARD 20)

add_executable(BagOfPairs App.cpp App.cpp BagIterator.h Bag.cpp BagIterator.cpp ExtendedTest.cpp ShortTest.cpp)
