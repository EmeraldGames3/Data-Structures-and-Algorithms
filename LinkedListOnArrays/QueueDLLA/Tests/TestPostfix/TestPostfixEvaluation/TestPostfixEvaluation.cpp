#include "TestPostfixEvaluation.h"
#include <string>
#include <cassert>
#include <iostream>
#include "../../../Postfix/PostfixEvaluation/PostfixEvaluation.h"

using std::string;

void testPostFixEvaluation(){
    string expression1 = "3 4 2 * 1 5 - 2 ^ / +";
    assert(evaluatePostfixExpression(expression1) == 3);

    string expression2 = "2 3 + 5 * 4 6 - /";
    assert(evaluatePostfixExpression(expression2) == -12);

    string expression3 = "10 5 * 20 + 30 /";
    assert(evaluatePostfixExpression(expression3) == 2);

    string expression4 = "5 2 4 * + 7 -";
    assert(evaluatePostfixExpression(expression4) == 6);

    std::cout << "Test postfix evaluation\n";
}