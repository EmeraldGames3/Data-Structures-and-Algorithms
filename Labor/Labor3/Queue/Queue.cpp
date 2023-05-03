#include "Queue.h"
#include <exception>
#include <iostream>

using namespace std;

Queue::Queue() {
    capacity = 10;
//    array = new DLLANode[capacity];
    array = new DLLANode[INT16_MAX]; //TODO remove this after you have implemented resize
    head = -1;
    tail = -1;
    size = 0;
}

void Queue::resize(int newSize) {

}

void Queue::automaticResize() {
    if (size == capacity)
        resize(capacity * 2);
//    if (size <= capacity / 4 && capacity >= 10)
//        resize(capacity / 2); //TODO uncomment this after resize works
}

void Queue::push(TElem elem) {
	DLLANode newNode{};

    if(size == 0){
        //Queue is empty
        newNode.data = elem;
        newNode.previous = -1;
        newNode.next = -1;
        array[0] = newNode;
        tail = 0;
        head = 0;
        size = 1;
        return;
    }

    newNode.data = elem;
    newNode.previous = tail;
    newNode.next = -1;

    array[tail].next = tail + 1;
    array[tail + 1] = newNode;
    tail += 1;
    size++;
}

TElem Queue::top() const {
    if(isEmpty())
        throw std::runtime_error("Queue is empty");

	return array[head].data;
}

TElem Queue::pop() {
    if(isEmpty())
        throw std::runtime_error("Queue is empty");

    TElem data = array[head].data;

    if(head == tail){
        tail = -1;
        head = -1;
        size = 0;
        return data;
    }

    if(size == 2){
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

	return data;
}


bool Queue::isEmpty() const {
	return size == 0;
}

Queue::~Queue() {
	delete[] array;
}
