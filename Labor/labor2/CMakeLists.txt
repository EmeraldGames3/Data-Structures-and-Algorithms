cmake_minimum_required(VERSION 3.24)
project(labor2)

set(CMAKE_CXX_STANDARD 20)

add_executable(labor2 App.cpp Queue/Queue.cpp Queue/QueueTest/ShortTest.cpp Queue/QueueTest/ExtendedTest.cpp LocationQueue/LocationQueue.cpp LocationQueue/Location.cpp IO/IO.cpp Robot/Robot.cpp)
