#include "LinkedList.h"

/**
 * @brief Default constructor fo the DLL class
 * @warning The head and tail are initialised to NULL_NODE
 * @details The programmer is responsible for further initialisation of the DLL
 */
DoubleLinkedList::DoubleLinkedList() {
    head = Node::NULL_NODE();
    tail = head;
}

DoubleLinkedList::DoubleLinkedList(const Node &head) {
    this->head = head;
    this->tail = this->head;
}

DoubleLinkedList::DoubleLinkedList(const Node &head, const Node &tail) {
    this->head = head;
    this->tail = tail;
    this->head.setNext(&(this->tail));
    this->tail.setPrevious(&(this->head));
};

void DoubleLinkedList::deleteFirst() {

}

void DoubleLinkedList::deleteLast() {

}

void DoubleLinkedList::addFirst(TElem element) {

}

void DoubleLinkedList::addLast(TElem element) {

}

Node DoubleLinkedList::getHead() const {
    return head;
}

Node DoubleLinkedList::getTail() const {
    return tail;
}

bool DoubleLinkedList::isEmpty() const {
    if(head.isNULL()) return true;
    return false;
}

/**
 * @brief DLL destructor
 * @details Iterate through the linked list to delete all Nodes
 * @complexity θ(n)
 */
DoubleLinkedList::~DoubleLinkedList(){
    //We have no dynamically allocated memory to delete
    if(head.next() == nullptr) return; //The list has only on element
    if(*head.next() == tail) return; //The list has only two elements

    //TODO iterate through the list
}


