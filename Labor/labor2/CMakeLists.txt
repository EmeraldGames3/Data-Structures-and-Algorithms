cmake_minimum_required(VERSION 3.24)
project(labor2)

set(CMAKE_CXX_STANDARD 20)

add_executable(labor2 App.cpp Queue/Queue.cpp Tests/QueueTest/ShortTest.cpp Tests/QueueTest/ExtendedTest.cpp LocationQueue/LocationQueue.cpp LocationQueue/Location/Location.cpp IO/IO.cpp Robot/Robot.cpp Tests/LocationTests/LocationTests.cpp Tests/LocationTests/LocationTests.h Tests/LocationQueueTests/LocationQueueTests.cpp Tests/LocationQueueTests/LocationQueueTests.h Tests/TestAllFunctionalities.cpp Tests/TestAllFunctionalities.h)
