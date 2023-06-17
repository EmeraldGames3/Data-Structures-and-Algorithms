cmake_minimum_required(VERSION 3.25)
project(DataStructures)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructures main.cpp DynamicArray/DynamicArrayIterator.cpp DynamicArray/DynamicArray.cpp LinkedList/SLL/SLL.cpp LinkedList/SLL/SLL_Iterator.cpp LinkedList/DLL/DLL.cpp LinkedList/DLL/DLL_Iterator.cpp)
