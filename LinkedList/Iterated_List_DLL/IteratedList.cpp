#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"

/// Complexity: θ(1)
// Constructor
IteratedList::IteratedList() {
	this->head = nullptr;
    this->tail = nullptr;
}

/// Complexity: θ(n)
// Returns the number of elements from the list
int IteratedList::size() const {
	int count = 0;
    Node *current = head;
    while(current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

/// Complexity: θ(1)
// Verifies if the list is empty
bool IteratedList::isEmpty() const {
	if(head == nullptr)
        return true;
	return false;
}

/// Complexity: θ(1)
// Returns the first position from the list
ListIterator IteratedList::first() const {
	ListIterator it(*this);
    it.first();
    return it;
}

/// Complexity: θ(1)
// Returns the element from the given position
TElem IteratedList::getElement(ListIterator pos) const {
    // throws an exception if the position is not valid
	if(!pos.valid())
        throw std::exception();
    return pos.getCurrent();
}

/// Complexity: θ(1)
// Removes the element from position pos
TElem IteratedList::remove(ListIterator& pos) {
    // throws exception if the position is not valid
	if(!pos.valid())
        throw std::exception();
    Node *removedNode = pos.currentNode;
    TElem removedData = removedNode->data;

    // case 1: the node is the head
    if(removedNode->previous != nullptr)
        removedNode->previous->next = removedNode->next;
    else
        head = removedNode->next;
    // case 2: the node is the tail
    if(removedNode->next != nullptr)
        removedNode->next->previous = removedNode->previous;
    else
        tail = removedNode->previous;

    // after removal pos is positioned on the next element (the one after the removed one) or it is invalid if the last element was removed
    pos.next();
    delete removedNode;
    //returns the removed element
    return removedData;
}

/// Complexity: O(n)
// Searches for the first occurrence of an element
ListIterator IteratedList::search(TElem e) const{
	ListIterator it = first();
    while(it.valid()) {
        if (it.getCurrent() == e)
            // returns an iterator that points to the element, if it appears in the list
            return it;
        it.next();
    }
    // returns an invalid iterator if the element is not in the list
	return it;
}

/// Complexity: θ(1)
// Changes the element from the current position to the given one
TElem IteratedList::setElement(ListIterator pos, TElem e) {
    // throws exception if the position is not valid
    if(!pos.valid())
        throw std::exception();
    TElem oldData = pos.getCurrent();
    pos.currentNode->data = e;

    // returns the old value from the position
    return oldData;
}

/// Complexity: θ(1)
// Adds a new element after the current element from the iterator
void IteratedList::addToPosition(ListIterator& pos, TElem e) {
    // throws an exception if pos is not valid
    if(!pos.valid())
        throw std::exception();
    Node *newNode = new Node{e, pos.currentNode->next, pos.currentNode};
    if(pos.currentNode->next != nullptr)
        pos.currentNode->next->previous = newNode;
    else
        tail = newNode;

    // after the addition, pos points to the newly added element
    pos.currentNode->next = newNode;
    // currentNode becomes newNode
    pos.currentNode = newNode;
}

/// Complexity: θ(1)
// Adds a new element to the end of the list
void IteratedList::addToEnd(TElem e) {
	Node *newNode = new Node{e, nullptr, tail};
    if(isEmpty())
        head = newNode;
    else
        tail->next = newNode;
    tail = newNode;
}

/// Complexity: θ(1)
// Adds a new element to the beginning of the list
void IteratedList::addToBeginning(TElem e) {
    Node *newNode = new Node{e, head, nullptr};
    if(isEmpty())
        tail = newNode;
    else
        head->previous = newNode;
    head = newNode;
}

/// Complexity: O(n)
// Destructor
IteratedList::~IteratedList() {
	Node *current = head;
    while(current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}