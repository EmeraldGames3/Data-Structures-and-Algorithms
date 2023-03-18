#pragma once
#include "Node/Node.h"

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM (-11111)

class DoubleLinkedList{
private:
    Node head;
    Node tail;

public:
    DoubleLinkedList();

    ~DoubleLinkedList();

    [[nodiscard]] TElem getHead() const;

    [[nodiscard]] TElem getTail() const;

    void deleteFirst();

    void deleteLast();

    void addFirst(TElem element);

    void addLast(TElem element);

    [[nodiscard]] bool isEmpty() const;
};