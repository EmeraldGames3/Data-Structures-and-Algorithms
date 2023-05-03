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

bool isDigit(char character){
    return character >= '0' && character <= '9';
}

string infixToPostfix(const string &expression){
    Stack stack;
    Queue queue;

    string currentNumber{};
    for (auto character : expression) {
        if(isDigit(character)){
            currentNumber += character;
            continue;
        }

        if(!currentNumber.empty()){
            queue.push(convertToNumber(currentNumber));
            currentNumber = "";
        }

        if(character == ' ') {
            continue;
        }

        if(isOperator(character)){
            //TODO modify this
            queue.push(character);
        }
        if(character == '('){
            //TODO implementation
        }
        if(character == ')'){
            //TODO implementation
        }

    }

    string result{};
    while (!queue.isEmpty()){
        int element = queue.pop();

        //TODO implement a better solution
        if(element >= 0 && element <= 256 && isOperator(static_cast<char>(element))){
            result += ((static_cast<char>(element)) + ' ');
        } else{
            result += (std::to_string(element) + ' ');
        }
    }

    return result;
}