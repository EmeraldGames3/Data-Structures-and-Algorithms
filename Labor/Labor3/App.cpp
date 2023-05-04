#include "Queue/Queue.h"
#include "Stack/Stack.h"
#include "Tests/test.h"
#include <iostream>
#include <string>
#include "Postfix/postfix.h"

using std::string;

int main() {
    test();

    string expression;
    std::cout << "Enter an expression: ";

    std::getline(std::cin, expression);!
    std::cout << postfix(expression);
}