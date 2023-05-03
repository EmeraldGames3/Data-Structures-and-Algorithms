#include "Stack.h"
#include <exception>
#include <stdexcept>

Stack::Stack() {
    head = -1;
    size = 0;
    capacity = 100000; //TODO change this
    array = new SLLANode[capacity];
}

void Stack::push(TElem elem) {
    SLLANode newNode{};
    newNode.data = elem;
    newNode.next = head;

    if(head == -1){
        array[capacity - 1] = newNode;
    }

    array[head - 1] = newNode;
    head--;
    size++;
}

TElem Stack::top() const {
    if(isEmpty())
        throw std::runtime_error("Stack is empty");

    return array[head].data;
}

TElem Stack::pop() {
    if(isEmpty())
        throw std::runtime_error("Stack is empty");

    TElem data = array[head].data;
    head = array[head].next;

    size--;
    return data;
}

bool Stack::isEmpty() const {
    return head == -1;
}

Stack::~Stack() {
    delete[] array;
}

