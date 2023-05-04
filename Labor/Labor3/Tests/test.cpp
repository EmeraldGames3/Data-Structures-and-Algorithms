#include "test.h"
#include <iostream>
#include "TestPostfix/TestPostFixConversion/testPostfixConversion.h"
#include "TestQueue/ShortTest.h"
#include "TestQueue/ExtendedTest.h"
#include "TestStack/StackTest.h"
#include "TestPostfix/TestPostfixEvaluation/TestPostfixEvaluation.h"
#include "TestPostfix/testPostfix.h"

void test(){
    std::cout << "Test Queue:\n";
    testAll();
    testAllExtended();
    std::cout << "\nTest Stack:\n";
    testStack();
    std::cout << "\nTest Infix conversion:\n";
    testInfixConversion();
    std::cout << "\nTest Postfix evaluation:\n";
    testPostFixEvaluation();
    std::cout << "\nTest Postfix:\n";
    testPostfix();
}