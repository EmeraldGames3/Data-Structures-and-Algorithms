cmake_minimum_required(VERSION 3.25)
project(Labor3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labor3 App.cpp PostfixConversion/PostFixConversion.cpp Tests/TestQueue/ExtendedTest.cpp Tests/TestQueue/ShortTest.cpp Tests/test.cpp Tests/TestPostFixConversion/testPostfixConversion.cpp Stack/Stack.cpp Queue/Queue.cpp Tests/TestStack/StackTest.cpp)
