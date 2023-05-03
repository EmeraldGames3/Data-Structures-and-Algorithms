#include "PostFixConversion.h"
#include "../Queue/Queue.h"
#include "../Stack/Stack.h"

//Check if a character is an operator
bool isOperator(char character) {
    return character == '+' || character == '-' || character == '*' || character == '/' || character == '^';
}

// Function to check the precedence of an operator
int precedence(char character) {
    if (character == '^')
        return 3;
    else if (character == '*' || character == '/')
        return 2;
    else if (character == '+' || character == '-')
        return 1;
    else
        return 0;
}

int convertToNumber(const std::string &expression) {
    int result = 0;
    int sign = 1;
    int i = 0;
    if (expression[i] == '-') {
        sign = -1;
        i++;
    }
    for (; i < expression.length(); i++) {
        int digit = expression[i] - '0';
        result = result * 10 + digit;
    }
    return result * sign;
}

string infixToPostfix(const string &expression){
    Stack stack;
    Queue queue;

    for(auto character : expression){
        if(character == '('){

        }
    }
}