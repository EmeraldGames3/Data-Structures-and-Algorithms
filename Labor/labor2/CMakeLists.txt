cmake_minimum_required(VERSION 3.24)
project(labor2)

set(CMAKE_CXX_STANDARD 20)

add_executable(labor2 App.cpp Queue/QueueTest/ExtendedTest.cpp Queue/Queue.cpp Queue/QueueTest/ShortTest.cpp LinkedList/LinkedList.cpp LinkedList/LinkedList.h LinkedList/LinkedListTest/LinkedListTest.cpp LinkedList/LinkedListTest/LinkedListTest.h)
