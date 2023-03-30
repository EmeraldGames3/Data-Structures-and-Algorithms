#include "Stack.h"
#include <exception>

/**
 * Stack constructor
 * @complexity θ(1)
 */
Stack::Stack() : head(nullptr), tail(nullptr) {}

/**
 * Push an element to the end of the stack
 * @param elem
 * @complexity θ(1)
 */
void Stack::push(TElem elem) {
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
 * Get the first element in the stack
 * @complexity θ(1)
 * @throws exception if stack is empty
 */
TElem Stack::top() const {
    if (isEmpty()) throw std::exception();
    return tail->info;
}

/**
 * Get the last element in the stack and pop it out of the stack
 * @complexity θ(1)
 * @throws exception if the stack is empty
 */
TElem Stack::pop() {
    if (isEmpty()) throw std::exception();

    TElem temp = tail->info;
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node *deletedNode = tail;
        tail = tail->previous;
        delete deletedNode;
    }

    return temp;
}

/**
 * Check if the stack is empty
 * @complexity θ(1)
 */
bool Stack::isEmpty() const {
    return head == nullptr;
}

/**
 * Stack destructor
 * @complexity θ(n)
 */
Stack::~Stack() {
    Node *currentNode = head;
    while (currentNode != nullptr) {
        Node *nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}

