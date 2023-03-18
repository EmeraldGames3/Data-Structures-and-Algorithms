#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#ifndef NULL_TELEM
#define NULL_TELEM (-11111)
#endif //NULL_TELEM

struct Node{
    TElem info;
    Node *previous;
    Node *next;
};

class DoubleLinkedList{
public:
    Node *head;
    Node *tail;

    //Default constructor
    DoubleLinkedList();

    //Constructor with one parameter
    explicit DoubleLinkedList(TElem elem);

    //Constructor with two parameters
    DoubleLinkedList(TElem headElem, TElem tailElem);

    [[nodiscard]] bool isEmpty() const;

    void insertFirst(TElem elem);

    void deleteFirst();

    void insertLast(TElem elem);

    void deleteLast();

    //Destructor
    ~DoubleLinkedList();
};
