#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>

/// Complexity: θ(1)
// Initialise currentNode with the list's head
ListIterator::ListIterator(const IteratedList& list) : list(list) {
	currentNode = list.head;
}

/// Complexity: θ(1)
// The first element is initialised as the list's head
void ListIterator::first() {
	currentNode = list.head;
}

/// Complexity: θ(1)
void ListIterator::next() {
	if(currentNode == nullptr)
        throw std::exception();
    currentNode = currentNode->next;
}

/// Complexity: θ(1)
bool ListIterator::valid() const {
	if(currentNode != nullptr)
        return  true;
    return false;
}

/// Complexity: θ(1)
TElem ListIterator::getCurrent() const {
	if(currentNode == nullptr)
        throw std::exception();
    return currentNode->data;
}

// preConditions: -currentNode != nullptr

// postCondition: -currentNode != nullptr
//                -the element that the iterator was pointing to is removed from the list.
//                -the iterator points to the next element in the list, or to the end of the list if the deleted element
//                was the last element in the list
//                -the size is decremented by 1

/// Complexity: -best case: θ(1) (currentNode is the head or the tail)
///             -worst case: θ(size) (currentNode is the tail)
///             -average: O(n)
void ListIterator::deleteCurrent() {
    if (currentNode == nullptr)
        throw std::exception();

    // Case 1: the head is our currentNode
    if (currentNode == list.head) {
        Node *newNode = currentNode;
        delete currentNode;
        currentNode = newNode->next;
    // Case 2: the tail is our currentNode
    } else if(currentNode == list.tail) {
        Node *newNode = currentNode;
        delete currentNode;
        currentNode = newNode->previous;
    // Case 3: currentNode is a node different from the head and tail
    } else {
        Node* prev = list.head;
        // starting from the head we iterate until we reach our currentNode
        while (prev->next != currentNode)
            prev = prev->next;
        prev->next = currentNode->next;
        delete currentNode;
        currentNode = prev->next;
    }
}

///Pseudocode
//if currentNode is NIL:
//  throw exception
//if currentNode equals list.head:
//  set newNode to currentNode
//  delete currentNode
//  set currentNode to newNode.next
//else if currentNode equals list.tail:
//  set newNode to currentNode
//  delete currentNode
//  set currentNode to newNode.previous
//else:
//  set prev to list.head
//  while prev.next does not equal currentNode:
//  set prev to prev.next
//  set prev.next to currentNode.next
//  delete currentNode
//  set currentNode to prev.next