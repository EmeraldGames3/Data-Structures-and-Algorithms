#include "Queue.h"
#include <exception>
#include <iostream>

using namespace std;

Queue::Queue() {
    capacity = 10;
    array = new DLLANode[capacity];
    head = -1;
    tail = -1;
    size = 0;
    firstEmpty = 0;
}

void Queue::resize(int newCapacity) {
    auto *newArray = new DLLANode[newCapacity];

    for(int it = head, i = 0; it != -1; it = array[it].next, i++){
        newArray[i].data = array[it].data;
        newArray[i].previous = array[it].previous;
        newArray[i].next = array[it].next;
    }

    delete[] array;
    array = newArray;
    capacity = newCapacity;
    firstEmpty = size;
}

void Queue::automaticResize() {
    if (size == capacity)
        resize(capacity * 2);
//    if (size <= capacity / 4 && capacity >= 10) //TODO make resizing down work
//        resize(capacity / 2);
}

void Queue::push(TElem elem) {
    DLLANode newNode{};

    if(size == 0){
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

    if(firstEmpty == capacity)
        //Start filling the array from the front
        firstEmpty = 0;
    else
        firstEmpty++;

    size++;
    automaticResize();
}

TElem Queue::top() const {
    if(isEmpty())
        throw std::runtime_error("Queue is empty");

	return array[head].data;
}

TElem Queue::pop() {
    //TODO find out why this function does not work in testMix and testQuantity

    if(isEmpty())
        throw std::runtime_error("Queue is empty");

    TElem data = array[head].data;
    firstEmpty = head;

    if(head == tail){
        tail = -1;
        head = -1;
        firstEmpty = 0;
        size = 0;
        return data;
    }

    if(size == 2){
        firstEmpty = head;
        head = tail;
        array[tail].previous = -1;
        size = 1;
        return data;
    }

    int newHead;
    newHead = array[head].next;
    array[newHead].previous = -1;
    head = newHead;
    size--;

    automaticResize();
    return data;
}

bool Queue::isEmpty() const {
	return size == 0;
}

Queue::~Queue() {
	delete[] array;
}