#include "LinkedList.h"
#include <exception>

DoubleLinkedList::DoubleLinkedList() {
    head.setNextNode(nullptr);
    head.setPreviousNode(nullptr);
    tail.setNextNode(nullptr);
    tail.setPreviousNode(nullptr);
}

void DoubleLinkedList::deleteFirst() {
    if(isEmpty()) throw std::exception();
}

void DoubleLinkedList::deleteLast() {
    if(isEmpty()) throw std::exception();
}

void DoubleLinkedList::addFirst(TElem element) {
    Node newNode = Node();
    newNode.setElement(element);
}

void DoubleLinkedList::addLast(TElem element) {
    Node newNode = Node();
    newNode.setElement(element);
}

TElem DoubleLinkedList::getHead() const {
    return head.getElement();
}

TElem DoubleLinkedList::getTail() const {
    return tail.getElement();
}

bool DoubleLinkedList::isEmpty() const {
    if(head.next() == nullptr && head.previous() == nullptr)
        return false;
    return true;
}

DoubleLinkedList::~DoubleLinkedList() {

}
