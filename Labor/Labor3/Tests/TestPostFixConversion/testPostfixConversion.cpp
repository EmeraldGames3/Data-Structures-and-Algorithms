#include "testPostfixConversion.h"
#include <cassert>
#include "../../PostfixConversion//PostFixConversion.h"
#include <iostream>

void testIsOperator() {
    assert(isOperator('+'));
    assert(isOperator('-'));
    assert(isOperator('*'));
    assert(isOperator('/'));
    assert(isOperator('^'));
    assert(!isOperator('a'));
    assert(!isOperator('5'));
    assert(!isOperator('('));
    assert(!isOperator(')'));
    std::cout << "Test operator\n";
}

void testPrecedence() {
    assert(precedence('^') == 3);
    assert(precedence('*') == 2);
    assert(precedence('/') == 2);
    assert(precedence('+') == 1);
    assert(precedence('-') == 1);
    assert(precedence('a') == 0);
    std::cout << "Test precedence\n";
}

void testInfixConversion(){
    testIsOperator();
    testPrecedence();
};