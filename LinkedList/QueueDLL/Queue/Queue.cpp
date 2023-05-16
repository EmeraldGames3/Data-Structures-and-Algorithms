#include "Queue.h"
#include <exception>
#include <iostream>

using namespace std;

/**
 * Queue constructor
 * @complexity θ(1)
 */
Queue::Queue() : head(nullptr), tail(nullptr) {}

/**
 * Add an element to the end of the queue
 * @complexity θ(1)
 */
void Queue::push(TElem elem) {
    if (isEmpty()) {
        head = new Node;
        head->info = elem;
        head->previous = head;
        head->next = tail;
        tail = head;
    } else {
        Node *newNode = new Node;
        newNode->info = elem;
        newNode->next = nullptr;
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

/**
 * Get the first element in the queue
 * @complexity θ(1)
 * @throws exception if queue is empty
 */
TElem Queue::top() const {
    if (isEmpty()) throw std::exception();
    return head->info;
}

/**
 * Get the first element in the queue and pop it out of the queue
 * @complexity θ(1)
 * @throws exception if the queue is empty
 */
TElem Queue::pop() {
    if (isEmpty()) throw std::exception();

    TElem temp = head->info;
    Node *deletedNode = head;
    head = head->next;

    if (head == nullptr)
        tail = nullptr;
    else
        head->previous = nullptr;

    delete deletedNode;
    return temp;
}

/**
 * Check if the queue is empty
 * @complexity θ(1)
 */
bool Queue::isEmpty() const { return head == nullptr; }

/**
 * Queue destructor
 * @complexity θ(n)
 */
Queue::~Queue() {
    Node *currentNode = head;
    while (currentNode != nullptr) {
        Node *nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}