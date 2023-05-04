#include "PostFixConversion.h"
#include "../../Queue/Queue.h"
#include "../../Stack/Stack.h"
#include <iostream>

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

//Convert a string to a number
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

bool isDigit(char character) {
    return character >= '0' && character <= '9';
}

string infixToPostfix(const string &expression) {
    Stack operatorStack;
    Queue operatorQueue;
    Queue queue;
    const int operatorAsInt = INT16_MAX;

    operatorStack.push(int('('));

    string currentNumber{};
    for (auto character: expression) {
        if (isDigit(character)) {
            currentNumber += character;
            continue;
        }

        if (!currentNumber.empty()) {
            queue.push(convertToNumber(currentNumber));
            currentNumber = "";
        }

        if (character == ' ') {
            continue;
        }

        if (character == '(') {
            operatorStack.push(int('('));
        }

        if (isOperator(char(character))) {
            while (precedence(char(operatorStack.top())) >= precedence(char(character))) {
                operatorQueue.push(int(operatorStack.pop()));
                queue.push(operatorAsInt);
            }
            operatorStack.push(int(character));
        }

        if (character == ')') {
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
        int element = queue.pop();

        if (element == operatorAsInt) {
            result += char(operatorQueue.pop());
        } else {
            result += (std::to_string(element));
        }

        result += ' ';
    }
    return result;
}