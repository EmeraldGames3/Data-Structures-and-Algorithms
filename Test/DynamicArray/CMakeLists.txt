cmake_minimum_required(VERSION 3.24)
project(DynamicArray)

set(CMAKE_CXX_STANDARD 20)

add_executable(DynamicArray main.cpp Example.cpp Example.h DArray.cpp DynamicArray.h)
