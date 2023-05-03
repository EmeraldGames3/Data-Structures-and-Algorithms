#include "test.h"
#include <iostream>
#include "TestPostFixConversion/testPostfixConversion.h"
#include "TestQueue/ShortTest.h"
#include "TestQueue/ExtendedTest.h"
#include "TestStack/StackTest.h"

void test(){
    std::cout << "Test Queue:\n";
    testAll();
    testAllExtended();
    std::cout << "\nTest Stack:\n";
    testStack();
    std::cout << "\nTest Infix conversion:\n";
    testInfixConversion();
}