cmake_minimum_required(VERSION 3.24)
project(DSA_L2_Iterated_List_DLL)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSA_L2_Iterated_List_DLL ExtendedTest.h App.cpp ExtendedTest.cpp IteratedList.cpp ListIterator.cpp ShortTest.cpp)
