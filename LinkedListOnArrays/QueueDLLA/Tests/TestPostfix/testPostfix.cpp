#include "testPostfix.h"
#include "../../Postfix/postfix.h"
#include <cassert>
#include <iostream>

void testPostfix(){
    // Test addition
    assert(postfix("1 + 2") == 3);
    assert(postfix("1 + 2 + 3") == 6);
    assert(postfix("1 + 2 + 3 + 4") == 10);

    // Test subtraction
    assert(postfix("3 - 1") == 2);
    assert(postfix("3 - 2 - 1") == 0);
    assert(postfix("4 - 3 - 2 - 1") == -2);

    // Test multiplication
    assert(postfix("2 * 3") == 6);
    assert(postfix("2 * 3 * 4") == 24);
    assert(postfix("2 * 3 * 4 * 5") == 120);

    // Test division
    assert(postfix("6 / 2") == 3);
    assert(postfix("12 / 3 / 2") == 2);
    assert(postfix("20 / 5 / 2 / 2") == 1);

    // Test exponentiation
    assert(postfix("2 ^ 3") == 8);
    assert(postfix("8 ^ 2") == 64);
    assert(postfix("2 ^ 9") == 512);

    // Test mixed expressions
    assert(postfix("1 + 2 * 3") == 7);
    assert(postfix("1 + 2 * 3 ^ 2") == 19);
    assert(postfix("(1 + 2) * 3") == 9);
    assert(postfix("(1 + 2) * (3 + 4)") == 21);
    assert(postfix("1 + (2 * (3 + 4))") == 15);

    std::cout << "Test postfix conversion and evaluation\n";
}