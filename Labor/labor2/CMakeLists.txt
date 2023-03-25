cmake_minimum_required(VERSION 3.24)
project(labor2)

set(CMAKE_CXX_STANDARD 20)

add_executable(labor2 App.cpp Queue/QueueTest/ExtendedTest.cpp LocationQueue/Queue.cpp Queue/QueueTest/ShortTest.cpp IO/IO.cpp IO/IO.h Robot/Robot.cpp Robot/Robot.h LocationQueue/Location.cpp LocationQueue/Location.h)
