#include "postfix.h"

int postfix(const string &expression){
    return evaluatePostfixExpression(infixToPostfix(expression));
}