#pragma once

#include <string>

using std::string;

bool isOperator(char character);

int precedence(char character);

int convertToNumber(const string& expression);

string infixToPostfix(const string &expression);