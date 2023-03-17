#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM -11111

struct Node{
    TElem element;
    Node *next;
    Node *previous;
};

class DoubleLinkedList{
private:
    Node head{};
    Node tail{};

public:
    DoubleLinkedList();

    TElem getHead() const;

    TElem getTail() const;

    void deleteFirst();

    void deleteLast();

    void addFirst();

    void addLast();
};