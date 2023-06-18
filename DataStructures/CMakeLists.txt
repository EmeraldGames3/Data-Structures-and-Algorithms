cmake_minimum_required(VERSION 3.25)
project(DataStructures)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructures main.cpp DynamicArray/DynamicArrayIterator.cpp DynamicArray/DynamicArray.cpp LinkedList/SLL/SLL.cpp LinkedList/SLL/SLL_Iterator.cpp LinkedList/DLL/DLL.cpp LinkedList/DLL/DLL_Iterator.cpp LinkedListOnArrays/SLLA/SLLA.cpp LinkedListOnArrays/SLLA/SLLA.h LinkedListOnArrays/SLLA/SLLAIterator.cpp LinkedListOnArrays/SLLA/SLLAIterator.h LinkedListOnArrays/DLLA/DLLA.cpp LinkedListOnArrays/DLLA/DLLA.h LinkedListOnArrays/DLLA/DLLAIterator.cpp LinkedListOnArrays/DLLA/DLLAIterator.h)
