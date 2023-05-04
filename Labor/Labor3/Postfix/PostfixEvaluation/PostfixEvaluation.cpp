#include "PostfixEvaluation.h"

int convertToNumber2(const string &expression) {
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

int evaluatePostfixExpression(const string &expression){
    Stack operands;
    string token;
    string operators = "+-*/^";

    // Iterate over each token in the expression
    for (size_t i = 0; i < expression.length(); i++) {
        token = "";
        while (i < expression.length() && expression[i] != ' ') {
            token += expression[i];
            i++;
        }

        if (operators.find(token) == string::npos) {
            // Token is an operand, push onto the stack
            operands.push(convertToNumber2(token));
        } else {
            // Token is an operator, pop operands and evaluate
            int rightOperand = operands.pop();
            int leftOperand = operands.pop();

            if (token == "+")
                operands.push(leftOperand + rightOperand);

            else if (token == "-")
                operands.push(leftOperand - rightOperand);

            else if (token == "*")
                operands.push(leftOperand * rightOperand);

            else if (token == "/")
                operands.push(leftOperand / rightOperand);

            else if (token == "^") {
                int result = 1;
                for (int j = 0; j < rightOperand; j++)
                    result *= leftOperand;

                operands.push(result);
            }
        }
    }

    // The final result is the only element left on the stack
    return operands.top();
}