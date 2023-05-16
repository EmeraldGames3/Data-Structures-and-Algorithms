
#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"

IteratedList::IteratedList() {
    head = nullptr;
    tail = nullptr;
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
    if (head == nullptr)
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
    Node *removedNode = pos.currentNode;
    TElem removedData = removedNode->data;

    if (removedNode == head) {
        head = head->next;
        pos.next();
        delete removedNode;
        return removedData;
    }

    auto it = first();
    while (it.currentNode->next != removedNode)
        it.next();

    it.currentNode->next = removedNode->next;

    pos.next();
    delete removedNode;
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
    pos.currentNode->data = e;

    // returns the old value from the position
    return oldData;
}

void IteratedList::addToPosition(ListIterator &pos, TElem e) {
    // throws an exception if pos is not valid
    if (!pos.valid())
        throw std::exception();
    Node *newNode = new Node{e, pos.currentNode->next};

    if(pos.currentNode->next == nullptr)
        tail = newNode;

    pos.currentNode->next = newNode;
    pos.currentNode = newNode;
}

void IteratedList::addToEnd(TElem e) {
    Node *newNode = new Node{e, nullptr};
    if (isEmpty())
        head = newNode;
    else
        tail->next = newNode;
    tail = newNode;
}

IteratedList::~IteratedList() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

void IteratedList::addToBeginning(TElem e) {
    Node *newNode = new Node{e, head};
    if (isEmpty())
        tail = newNode;
    head = newNode;
}
