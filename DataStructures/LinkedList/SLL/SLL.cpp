#include "SLL.h"
#include <stdexcept>

SLL::SLL() {
    head = nullptr;
    size = 0;
}

SLL::~SLL() {
    SLLNode *deletedNode;
    SLLNode *current = head;
    while (current != nullptr) {
        deletedNode = current;
        current = current->next;
        delete deletedNode;
    }
}

int SLL::getSize() const {
    return size;
}

bool SLL::isEmpty() const {
    if (size == 0)
        return true;
    return false;
}

TElem SLL::deleteElement(TElem element) {
    if (isEmpty())
        return NULL_TELEM;

    SLLNode *current = head;
    SLLNode *previous;
    while (current != nullptr){
        previous = current;
        current = current->next;
        if(current->info == element){
            auto deletedValue = current->info;
            previous->next = current->next;

            delete current;
            size--;
            return deletedValue;
        }
    }

    return NULL_TELEM
}

void SLL::addFirst(TElem element) {
    auto *newNode = new SLLNode;
    newNode->info = element;
    newNode->next = head;
    this->head = newNode;
    size++;
}

void SLL::AddBeforeNode(SLLNode *currentNode, TElem element) {
    SLLNode *previous = head;
    while (previous != nullptr && previous->next != currentNode){
        previous = previous->next;
    }

    if(previous == nullptr){
        throw std::invalid_argument("Node does not exist");
    }

    auto *newNode = new SLLNode{element, currentNode};
    previous->next = newNode;
}

void SLL::addAfterNode(SLLNode *currentNode, TElem element) {
    auto *newNode = new SLLNode;
    newNode->info = element;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

void SLL::insertPosition(int position, TElem element) {
    if (position < 0 || position >= size)
        throw std::invalid_argument("Invalid position");

    SLLNode *current = head;
    for (int i = 0; i <= position; i++) {
        current = current->next;
    }
    auto *newNode = new SLLNode{element, current->next};
    current->next = newNode;
}

TElem SLL::deleteFirst() {
    if (size == 0) {
        throw std::invalid_argument("List is empty");
    }

    SLLNode *deletedNode = head;
    auto deletedValue = head->info;
    head = head->next;
    delete deletedNode;
    size--;
    return deletedValue;
}