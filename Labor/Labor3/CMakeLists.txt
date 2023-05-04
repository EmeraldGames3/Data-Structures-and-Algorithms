cmake_minimum_required(VERSION 3.25)
project(Labor3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labor3 App.cpp Postfix/PostfixConversion/PostFixConversion.cpp Tests/TestQueue/ExtendedTest.cpp Tests/TestQueue/ShortTest.cpp Tests/test.cpp Tests/TestPostfix/TestPostFixConversion/testPostfixConversion.cpp Stack/Stack.cpp Queue/Queue.cpp Tests/TestStack/StackTest.cpp Postfix/PostfixEvaluation/PostfixEvaluation.cpp Postfix/PostfixEvaluation/PostfixEvaluation.h Tests/TestPostfix/TestPostfixEvaluation/TestPostfixEvaluation.cpp Tests/TestPostfix/TestPostfixEvaluation/TestPostfixEvaluation.h Postfix/postfix.cpp Postfix/postfix.h Tests/TestPostfix/testPostfix.cpp Tests/TestPostfix/testPostfix.h)
