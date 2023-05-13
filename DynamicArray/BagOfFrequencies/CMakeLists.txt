cmake_minimum_required(VERSION 3.25)
project(BagOfFrequencies)

set(CMAKE_CXX_STANDARD 20)

add_executable(BagOfFrequencies App.cpp ExtendedTest.cpp ShortTest.cpp BagIterator.cpp Bag.cpp)
