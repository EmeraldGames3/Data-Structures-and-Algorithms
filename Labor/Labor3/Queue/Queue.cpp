#include "Queue.h"
#include <exception>
#include <iostream>

using namespace std;

/**
 * Queue constructor
 * @complexity θ(1)
 */
Queue::Queue() {
    capacity = 10;
    array = new DLLANode[capacity];
    head = -1;
    tail = -1;
    size = 0;
    firstEmpty = 0;
}

/**
 * Resize the array to a new capacity
 * @complexity θ(n), for every case this function performs exactly n steps
 */
void Queue::resize(int newCapacity) {
    auto *newArray = new DLLANode[newCapacity];

    // Copy the elements from the old array to the new array
    int i = head;
    int j = 0;
    while (i != -1) {
        newArray[j].data = array[i].data;
        newArray[j].previous = j - 1;
        newArray[j].next = j + 1;
        i = array[i].next;
        j++;
    }

    // Set the head and tail of the new array
    newArray[0].previous = -1;
    newArray[j - 1].next = -1;

    if (size == 0) {
        head = -1;
        tail = -1;
    } else {
        head = 0;
        tail = j - 1;
    }

    delete[] array;
    array = newArray;
    capacity = newCapacity;
    firstEmpty = size;
}

/**
 * Automatically resizes the array
 * @complexityΩ θ(1)
 * @complexityθ θ(1) (costuri amortizate)
 * @complexityO θ(n)
 */
void Queue::automaticResize() {
    if (size >= capacity)
        resize(capacity * 2);
//    if (size <= capacity / 4 && capacity > 10)
//        resize(capacity / 2);
}

/**
 * Add an element to the end of the queue
 * @complexity θ(1)
 */
void Queue::push(TElem elem) {
    DLLANode newNode{};

    if (size == 0) {
        //Queue is empty
        newNode.data = elem;
        newNode.previous = -1;
        newNode.next = -1;
        array[firstEmpty] = newNode;
        tail = firstEmpty;
        head = firstEmpty;
        firstEmpty = 1;
        size = 1;
        return;
    }

    newNode.data = elem;
    newNode.previous = tail;
    newNode.next = -1;

    array[tail].next = firstEmpty;
    array[firstEmpty] = newNode;
    tail = firstEmpty;

    if (firstEmpty == capacity)
        //Start filling the array from the front
        firstEmpty = 0;
    else
        firstEmpty++;

    size++;
    automaticResize();
}

/**
 * Get the first element in the queue
 * @complexity θ(1)
 * @throws exception if queue is empty
 */
TElem Queue::top() const {
    if (isEmpty())
        throw std::runtime_error("Queue is empty");

    return array[head].data;
}

/**
 * Get the first element in the queue and pop it out of the queue
 * @complexity θ(1)
 * @throws exception if the queue is empty
 */
TElem Queue::pop() {
    if (isEmpty())
        throw std::runtime_error("Queue is empty");

    TElem data = array[head].data;
    int poppedIndex = head;

    if (head == tail) {
        tail = -1;
        head = -1;
        firstEmpty = 0;
        size = 0;
        return data;
    }

    head = array[head].next;
    array[head].previous = -1;
    if (poppedIndex == firstEmpty)
        firstEmpty = head;

    size--;
    automaticResize();

    return data;
}

/**
 * Check if the queue is empty
 * @complexity θ(1)
 */
bool Queue::isEmpty() const {
    return size == 0;
}

/**
 * Queue destructor
 * @complexity θ(1)
 */
Queue::~Queue() {
    delete[] array;
}
