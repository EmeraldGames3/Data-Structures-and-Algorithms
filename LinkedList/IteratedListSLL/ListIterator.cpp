#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>

ListIterator::ListIterator(const IteratedList& list) : list(list) {
	currentNode = list.head;
}

void ListIterator::first() {
	currentNode = list.head;
}

void ListIterator::next() {
    if(currentNode == nullptr)
        throw std::exception();
    currentNode = currentNode->next;
}

bool ListIterator::valid() const {
    if(currentNode != nullptr)
        return  true;
    return false;
}

TElem ListIterator::getCurrent() const {
    if(currentNode == nullptr)
        throw std::exception();
    return currentNode->data;
}



