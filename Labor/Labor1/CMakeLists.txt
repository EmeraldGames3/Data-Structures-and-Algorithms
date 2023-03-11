cmake_minimum_required(VERSION 3.24)
project(Labor1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labor1 App.cpp SortedBag/SortedBag.cpp SortedBagIterator/SortedBagIterator.cpp Tests/ExtendedTest.cpp Tests/ShortTest.cpp)
