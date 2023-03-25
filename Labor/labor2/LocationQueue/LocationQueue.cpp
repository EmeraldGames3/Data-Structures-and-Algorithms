#include "LocationQueue.h"
#include <exception>

/**
 * @brief Constructor with implicit parameters for the Node struct
 * @details The implicit value of a Location is row = -1 and column = -1 which is an invalid Location
 **/
Node::Node(TElem _info, Node *_previous, Node *_next) : info(_info), previous(_previous), next(_next){}

LocationQueue::LocationQueue() : head(nullptr), tail(nullptr) {}

LocationQueue::LocationQueue(const LocationQueue &other) {
    head = nullptr;
    tail = nullptr;
    Node *currentNode = other.head;
    while (currentNode != nullptr) {
        push(currentNode->info);
        currentNode = currentNode->next;
    }
}

void LocationQueue::push(const TElem &elem) {
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

TElem LocationQueue::top() const {
    if(isEmpty()) throw std::exception();
    return head->info;
}

TElem LocationQueue::pop() {
    if (isEmpty()) throw std::exception();

    TElem temp = head->info;
    Node *deletedNode = head;
    head = head->next;

    if (head == nullptr) tail = nullptr;
    else head->previous = nullptr;

    delete deletedNode;
    return temp;
}

bool LocationQueue::isEmpty() const {
    return head == nullptr;
}

LocationQueue &LocationQueue::operator=(const LocationQueue &other) {
    if(this != &other){
        head = nullptr;
        tail = nullptr;
        Node *currentNode = other.head;
        while (currentNode != nullptr) {
            push(currentNode->info);
            currentNode = currentNode->next;
        }
    }
    return *this;
}

LocationQueue::~LocationQueue() {
    Node *currentNode = head;
    while (currentNode != nullptr) {
        Node *nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}