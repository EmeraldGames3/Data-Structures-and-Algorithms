#include "Example.h"
#include <iostream>

// Constructor
Example::Example(int value) : m_value(value) {}

// Public member function
void Example::printValue() const{
    std::cout << "Value is " << m_value << std::endl;
}
