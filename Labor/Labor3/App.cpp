#include "Queue/Queue.h"
#include "Stack/Stack.h"
#include "Tests/test.h"
#include <iostream>
#include <string>
#include "Postfix/postfix.h"
#include <cassert>

using std::string;

int main() {
    test();

    string expression;
    std::cout << "\nEnter an expression: ";

    std::getline(std::cin, expression);

    std::cout << infixToPostfix(expression) << '\n';
    std::cout << postfix(expression);
}