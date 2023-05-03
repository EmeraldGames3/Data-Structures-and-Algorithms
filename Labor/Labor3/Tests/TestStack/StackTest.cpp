#include "StackTest.h"
#include <cassert>
#include <iostream>
#include "../../Stack/Stack.h"

void testPushStack() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    assert(!s.isEmpty());
    assert(s.top() == 3);
    std::cout <<"Test push\n";
}

void testTopStack() {
    Stack s;
    s.push(1);
    s.push(2);
    assert(s.top() == 2);
    std::cout <<"Test top\n";
}

void testPopStack() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    assert(s.pop() == 3);
    assert(s.pop() == 2);
    assert(s.pop() == 1);
    assert(s.isEmpty());
    std::cout <<"Test pop\n";
}

void testIsEmptyStack() {
    Stack s;
    assert(s.isEmpty());
    s.push(1);
    assert(!s.isEmpty());
    std::cout <<"Test isEmpty\n";
}

void testStack() {
    testPushStack();
    testPopStack();
    testIsEmptyStack();
    testTopStack();
}