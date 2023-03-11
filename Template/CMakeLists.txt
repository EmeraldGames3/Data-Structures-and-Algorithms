cmake_minimum_required(VERSION 3.24)
project(Template)

set(CMAKE_CXX_STANDARD 20)

add_executable(Template main.cpp DynamicArray/DynamicArray.h DynamicArray/DynamicArray.cpp Utils/SortingAlgorithms.cpp Utils/SortingAlgorithms.h Utils/Random.cpp Utils/Random.h)
