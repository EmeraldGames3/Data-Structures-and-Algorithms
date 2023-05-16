
#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"

IteratedList::IteratedList() {
    head = -1;
    tail = -1;
    capacity = 99999999;
    array = new Node[capacity];
    firstEmpty = 0;

    for (int i = 0; i < capacity; i++) {
        array[i].next = i + 1;
    }
    array[capacity - 1].next = -1;
}

int IteratedList::size() const {
    int count = 0;
    ListIterator it = first();

    while (it.valid()) {
        count++;
        it.next();
    }
    return count;
}

bool IteratedList::isEmpty() const {
    if (head == -1)
        return true;
    return false;
}

ListIterator IteratedList::first() const {
    ListIterator it(*this);
    it.first();
    return it;
}

TElem IteratedList::getElement(ListIterator pos) const {
    // throws an exception if the position is not valid
    if (!pos.valid())
        throw std::exception();
    return pos.getCurrent();
}

TElem IteratedList::remove(ListIterator &pos) {
    // throws exception if the position is not valid
    if (!pos.valid())
        throw std::exception();
    int removedNode = pos.current;
    TElem removedData = array[removedNode].value;

    if (removedNode == head) {
        head = array[head].next;
        array[removedNode].next = firstEmpty;
        firstEmpty = removedNode;
        pos.next();
        return removedData;
    }

    auto it = first();
    while (array[it.current].next != removedNode)
        it.next();

    array[it.current].next = array[removedNode].next;
    array[removedNode].next = firstEmpty;
    firstEmpty = removedNode;

    pos.next();
    return removedData;
}

ListIterator IteratedList::search(TElem e) const {
    ListIterator it = first();
    while (it.valid()) {
        if (it.getCurrent() == e)
            // returns an iterator that points to the element, if it appears in the list
            return it;
        it.next();
    }
    // returns an invalid iterator if the element is not in the list
    return it;
}

TElem IteratedList::setElement(ListIterator pos, TElem e) {
    // throws exception if the position is not valid
    if (!pos.valid())
        throw std::exception();
    TElem oldData = pos.getCurrent();
    array[pos.current].value = e;

    // returns the old value from the position
    return oldData;
}

void IteratedList::addToPosition(ListIterator &pos, TElem e) {
    if (!pos.valid())
        throw std::exception();

    int newFirstEmpty = array[firstEmpty].next;
    array[firstEmpty] = Node{e, array[pos.current].next};
    array[pos.current].next = firstEmpty;

    if(pos.current == tail){
        tail = firstEmpty;
    }
    if(isEmpty()){
        head = firstEmpty;
        tail = firstEmpty;
    }

    firstEmpty = newFirstEmpty;
    pos.next();
}

void IteratedList::addToEnd(TElem e) {
    if(isEmpty()){
        head = firstEmpty;
        tail = firstEmpty;
        firstEmpty = array[firstEmpty].next;
        array[head].value = e;
        array[head].next = -1;
        return;
    }

    int newFirstEmpty = array[firstEmpty].next;
    array[firstEmpty] = Node{e, -1};
    array[tail] = array[firstEmpty];
    tail = firstEmpty;
    firstEmpty = newFirstEmpty;
}

IteratedList::~IteratedList() {
//    delete[] array;
}

void IteratedList::addToBeginning(TElem e) {
    array[firstEmpty] = Node{e, head};

    if (isEmpty())
        tail = firstEmpty;
    head = firstEmpty;

    firstEmpty = array[firstEmpty].next;
}