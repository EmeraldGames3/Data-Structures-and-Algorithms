cmake_minimum_required(VERSION 3.25)
project(Bag)

set(CMAKE_CXX_STANDARD 20)

add_executable(Bag App.cpp Bag.cpp ExtendedTest.cpp ShortTest.cpp BagIterator.cpp)
