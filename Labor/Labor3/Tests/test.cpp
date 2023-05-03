#include "test.h"
#include <iostream>

void test(){
    std::cout << "Test Queue:\n";
    testAll();
    testAllExtended();
    std::cout << "\nTest Stack:\n";
    testStack();
}