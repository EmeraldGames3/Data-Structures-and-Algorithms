cmake_minimum_required(VERSION 3.24)
project(labor2)

set(CMAKE_CXX_STANDARD 20)

add_executable(labor2 App.cpp Queue/QueueTests/ExtendedTest.cpp Queue/Queue.cpp Queue/QueueTests/ShortTest.cpp LinkedList/LinkedList.cpp LinkedList/LinkedList.h LinkedList/Node/Node.cpp LinkedList/Node/Node.h LinkedList/Node/NodeTest/NodeTest.cpp LinkedList/Node/NodeTest/NodeTest.h)
