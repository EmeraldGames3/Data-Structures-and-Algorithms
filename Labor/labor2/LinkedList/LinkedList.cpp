#include "LinkedList.h"

DoubleLinkedList::DoubleLinkedList() {
    head.next = nullptr;
    head.previous = nullptr;
    tail.next = nullptr;
    tail.previous = nullptr;
}

void DoubleLinkedList::deleteFirst() {

}

void DoubleLinkedList::deleteLast() {

}

void DoubleLinkedList::addFirst() {

}

void DoubleLinkedList::addLast() {

}

TElem DoubleLinkedList::getHead() const {
    return head.element;
}

TElem DoubleLinkedList::getTail() const {
    return tail.element
}
