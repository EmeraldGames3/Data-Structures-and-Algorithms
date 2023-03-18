#include "LinkedList.h"
#include <exception>

DoubleLinkedList::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DoubleLinkedList::DoubleLinkedList(TElem elem) {
    head = new Node;
    head->info = elem;
    head->previous = nullptr;
    head->next = nullptr;
    tail = head;
}

DoubleLinkedList::DoubleLinkedList(TElem headElem, TElem tailElem) {
    head = new Node;
    tail = new Node;

    head->info = headElem;
    head->next = tail;
    head->previous = nullptr;

    tail->info = tailElem;
    tail->previous = head;
    tail->next = nullptr;
}

bool DoubleLinkedList::isEmpty() const { return head == nullptr; }

void DoubleLinkedList::insertFirst(TElem elem) {
    if(isEmpty()){
        head = new Node;
        head->info = elem;
        head->previous = nullptr;
        head->next = nullptr;
        tail = head;
    }
    else if(head == tail){
        //List has 1 element
        head = new Node;
        head->info = elem;
        head->next = tail;
        head->previous = nullptr;
    }
    else{
        Node *newNode = new Node;
        newNode->info = elem;
        newNode->next = head;
        newNode->previous = nullptr;
        head = newNode;
    }
}

void DoubleLinkedList::deleteFirst() {
    if(isEmpty()) throw std::exception();
    else if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node *deletedNode = head;
        head = head->next;
        delete deletedNode;
    }
}

void DoubleLinkedList::insertLast(TElem elem) {
    if(isEmpty()){
        head = new Node;
        head->info = elem;
        head->previous = nullptr;
        head->next = nullptr;
        tail = head;
    }
    else if(head == tail){
        //List has 1 element
        tail = new Node;
        tail->info = elem;
        tail->next = nullptr;
        tail->previous = head;
    }
    else{
        Node *newNode = new Node;
        newNode->info = elem;
        newNode->next = nullptr;
        newNode->previous = tail;
        tail = newNode;
    }
}

void DoubleLinkedList::deleteLast() {
    if(isEmpty()) throw std::exception();
    else if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
    }else{
        Node *deletedNode = tail;
        tail = tail->previous;
        delete deletedNode;
    }
}

DoubleLinkedList::~DoubleLinkedList() {
    Node *currentNode = head;
    while (currentNode != nullptr) {
        Node *nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}
