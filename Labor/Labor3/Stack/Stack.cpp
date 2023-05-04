#include "Stack.h"
#include <exception>
#include <stdexcept>

/**
 * Stack constructor
 *  @complexity θ(1)
 */
Stack::Stack() {
    head = -1;
    size = 0;
    capacity = 10;
    array = new SLLANode[capacity];
}

/**
 * Resize the array to a new capacity
 * @complexity θ(n), for every case this function performs exactly n steps
 */
void Stack::resize(int newCapacity) {
    auto *newArray = new SLLANode[newCapacity];

    // Copy the elements from the old array to the new array.
    for(int i = 0; i < size; i++)
        newArray[i] = array[i];

    delete[] array;
    capacity = newCapacity;
    array = newArray;
}

/**
 * Automatically resizes the array
 * @complexityΩ θ(1)
 * @complexityθ θ(1) (costuri amortizate)
 * @complexityO θ(n)
 */
void Stack::automaticResize() {
    if(size == capacity)
        resize(capacity * 2);
    if(size <= capacity / 4 && capacity > 10)
        resize(capacity / 2);
}

/**
 * Push an element to the end of the stack
 * @param elem
 * @complexity θ(1)
 */
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

/**
 * Get the first element in the stack
 * @complexity θ(1)
 * @throws exception if stack is empty
 */
TElem Stack::top() const {
    if(isEmpty())
        throw std::runtime_error("Stack is empty");

    return array[head].data;
}

/**
 * Get the last element in the stack and pop it out of the stack
 * @complexity θ(1)
 * @throws exception if the stack is empty
 */
TElem Stack::pop() {
    if(isEmpty())
        throw std::runtime_error("Stack is empty");

    TElem data = array[head].data;
    head = array[head].next;

    size--;
    automaticResize();

    return data;
}

/**
 * Check if the stack is empty
 * @complexity θ(1)
 */
bool Stack::isEmpty() const {
    return head == -1;
}

/**
 * Stack destructor
 * @complexity θ(1)
 */
Stack::~Stack() {
    delete[] array;
}