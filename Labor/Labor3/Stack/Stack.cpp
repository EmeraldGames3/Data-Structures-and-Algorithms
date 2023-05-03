#include "Stack.h"
#include <exception>


Stack::Stack() {
    head = -1;
    size = 0;
    capacity = 10;
    array = new SLLANode[capacity];
}

void Stack::push(TElem elem) {

}

TElem Stack::top() const {
    return array[head].data;
}

TElem Stack::pop() {
    if(isEmpty())
        throw

    TElem data = array[head].data;

    size--;
    return data;
}

bool Stack::isEmpty() const {
    return head == -1;
}

Stack::~Stack() {
    delete[] array;
}

