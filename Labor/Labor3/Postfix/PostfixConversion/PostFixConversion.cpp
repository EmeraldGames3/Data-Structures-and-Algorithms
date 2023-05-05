#include "PostFixConversion.h"
#include "../../Queue/Queue.h"
#include "../../Stack/Stack.h"
#include <iostream>

// Check if a character is an operator
// @complexity θ(1)
bool isOperator(char character) {
    return character == '+' || character == '-' || character == '*' || character == '/' || character == '^';
}

// Function to check the precedence of an operator
// @complexity θ(1)
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

// Convert a string to a number
// @complexity θ(1)
int convertToNumber(const string &expression) {
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

// Check if a character is numeric
// @complexity θ(1)
bool isDigit(char character) {
    return character >= '0' && character <= '9';
}

/**
 * Convert an arithmetic expression from infix notation to postfix notation
 * @throws runtime_error if the expression is invalid
 * @complexity θ(n), we need to traverse the whole expression every time
 **/
string infixToPostfix(const string &expression) {
    Stack operatorStack; // Stack where operators are held
    Queue operatorQueue; // Queue where the operators are held in the correct order
    Queue queue; // Queue with the expression with INT32_MAX representing that an operator will be there
    const int operatorAsInt = INT32_MAX;

    //push ( onto the stack to have a reference for where the stack ends
    operatorStack.push(int('('));

    string currentNumber{};
    for (auto character: expression) {
        //Evaluate the expression character by character

        if (isDigit(character)) {
            //Build the numbers out of the characters
            currentNumber += character;
            continue;
        }

        if (!currentNumber.empty()) {
            //Push the number onto the queue
            queue.push(convertToNumber(currentNumber));
            currentNumber = "";
        }

        if (character == ' ') {
            //Ignore white spaces
            continue;
        }

        if (character == '(') {
            operatorStack.push(int('('));
        }

        if (isOperator(char(character))) {
            //Push the operator onto the stack
            //Pop operators from the stack based on their precedence and push them in the queue
            while (precedence(char(operatorStack.top())) >= precedence(char(character))) {
                operatorQueue.push(int(operatorStack.pop()));
                queue.push(operatorAsInt);
            }
            operatorStack.push(int(character));
        }

        if (character == ')') {
            //If a closing parenthesis is encountered pop all operators from the stack until you encounter its match
            //If no match is found throw runtime_error
            while (operatorStack.top() != '(') {
                queue.push(operatorAsInt);
                operatorQueue.push(operatorStack.pop());
            }
            operatorStack.pop();

            if (operatorStack.isEmpty()) {
                throw std::runtime_error("Invalid matching of parenthesis");
            }
        }
    }

    if (!currentNumber.empty()) {
        //push the last number onto the queue
        queue.push(convertToNumber(currentNumber));
    }

    while (!operatorStack.isEmpty() && char(operatorStack.top()) != '(') {
        //push the last operators onto the queue
        queue.push(operatorAsInt);
        operatorQueue.push(operatorStack.pop());
    }

    string result{};
    while (!queue.isEmpty()) {
        //Build the final expression
        int element = queue.pop();

        if (element == operatorAsInt) {
            //Add back the operators
            result += char(operatorQueue.pop());
        } else {
            //Add the operands in the expression
            result += (std::to_string(element));
        }

        result += ' ';
    }

    return result;
}