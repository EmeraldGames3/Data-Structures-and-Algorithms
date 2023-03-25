#include "Queue.h"
#include <exception>

/**
 * @brief Constructor with implicit parameters for the Node struct
 * @details The implicit value of a Location is row = -1 and column = -1 which is an invalid Location
 **/
Node::Node(TElem _info, Node *_previous, Node *_next) : info(_info), previous(_previous), next(_next){}

Queue::Queue() : head(nullptr), tail(nullptr) {}

void Queue::push(const TElem &elem) {
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

TElem Queue::top() const {
    if(isEmpty()) throw std::exception();
    return head->info;
}

TElem Queue::pop() {
    if (isEmpty()) throw std::exception();

    TElem temp = head->info;
    Node *deletedNode = head;
    head = head->next;

    if (head == nullptr) tail = nullptr;
    else head->previous = nullptr;

    delete deletedNode;
    return temp;
}

bool Queue::isEmpty() const {
    return head == nullptr;
}

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