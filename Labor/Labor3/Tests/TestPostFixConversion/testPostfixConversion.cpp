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

void testConvertToNumber(){
    std::string input1 = "123";
    int expected_output1 = 123;
    assert(convertToNumber(input1) == expected_output1);

    std::string input2 = "-456";
    int expected_output2 = -456;
    assert(convertToNumber(input2) == expected_output2);

    std::string input3 = "0";
    int expected_output3 = 0;
    assert(convertToNumber(input3) == expected_output3);

    std::string input4 = "999";
    int expected_output4 = 999;
    assert(convertToNumber(input4) == expected_output4);

    std::string input5 = "-789";
    int expected_output5 = -789;
    assert(convertToNumber(input5) == expected_output5);
    std::cout << "Test convert to number\n";
}

void testInfixToPostfix() {
    std::string input1 = "2 + 3 * 4";
    std::string output1 = "2 3 4 * + ";
    assert(infixToPostfix(input1) == output1);

    std::string input2 = "2 * (3 + 4)";
    std::string output2 = "2 3 4 + * ";
    assert(infixToPostfix(input2) == output2);

    std::string input3 = "(1 + 2) * 3 - 4 / 5";
    std::string output3 = "1 2 + 3 * 4 5 / - ";
    assert(infixToPostfix(input3) == output3);

    std::string input4 = "(3 + 4) * 2 + 1";
    std::string output4 = "3 4 + 2 * 1 + ";
    assert(infixToPostfix(input4) == output4);
    std::cout << "Test infix to postfix conversion\n";

    std::string input5 = "1 + 2 )";
    try {
        infixToPostfix(input5);
        assert(false);
    }catch (const std::runtime_error &exception){
        assert(true);
    }
}

void testInfixConversion(){
    testIsOperator();
    testPrecedence();
    testConvertToNumber();
    testInfixToPostfix();
}