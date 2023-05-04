#include "Stack.h"
#include <exception>
#include <stdexcept>

Stack::Stack() {
    head = -1;
    size = 0;
    capacity = 10;
    array = new SLLANode[capacity];
}

void Stack::resize(int newCapacity) {
    auto *newArray = new SLLANode[newCapacity];

    // Copy the elements from the old array to the new array.
    for(int i = 0; i < size; i++)
        newArray[i] = array[i];

    delete[] array;
    capacity = newCapacity;
    array = newArray;
}

void Stack::automaticResize() {
    if(size == capacity)
        resize(capacity * 2);
    if(size <= capacity / 4 && capacity > 10)
        resize(capacity / 2);
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

    automaticResize();
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
    automaticResize();

    return data;
}

bool Stack::isEmpty() const {
    return head == -1;
}

Stack::~Stack() {
    delete[] array;
}