#include "Queue.h"
#include <exception>
#include <iostream>

using namespace std;

Queue::Queue() {
    linkedList = DoubleLinkedList();
}

void Queue::push(TElem elem) {
    linkedList.insertLast(elem);
}

TElem Queue::top() const {
    return linkedList.head->info;
}

TElem Queue::pop() {
    TElem temp= linkedList.head->info;
    linkedList.deleteFirst();
    return temp;
}

bool Queue::isEmpty() const { return linkedList.isEmpty(); }


Queue::~Queue() = default;