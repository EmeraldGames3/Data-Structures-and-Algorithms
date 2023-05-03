cmake_minimum_required(VERSION 3.25)
project(Labor3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labor3 App.cpp Stack/Stack.cpp Tests/StackTest/StackTest.cpp Tests/TestQueue/ExtendedTest.cpp Queue/Queue.cpp Tests/TestQueue/ShortTest.cpp Tests/test.cpp Tests/test.h)
