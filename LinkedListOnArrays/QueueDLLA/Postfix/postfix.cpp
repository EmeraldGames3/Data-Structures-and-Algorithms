#include "postfix.h"
#include <iostream>

/**
 * Convert an expression in infix notation to postfix notation and evaluate the expression
 * @param expression An arithmetic expression in infix notation
 * @return The result of the expression
 * @complexity θ(n)
 */
int postfix(const string &expression){
    return evaluatePostfixExpression(infixToPostfix(expression));
}