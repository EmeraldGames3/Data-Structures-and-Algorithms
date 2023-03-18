#pragma once
#include "Node/Node.h"

//DO NOT CHANGE THIS PART
typedef int TElem;
#ifndef NULL_TELEM
#define NULL_TELEM -11111
#endif //NULL_TELEM

class DoubleLinkedList{
private:
    Node head;
    Node tail;

public:
    //Default constructor
    DoubleLinkedList();

    //Constructor with 1 parameter
    explicit DoubleLinkedList(const Node &head);

    //Constructor with 2 parameters
    DoubleLinkedList(const Node &head, const Node &tail);

    //Destructor
    ~DoubleLinkedList();

    //Get the first element in th list
    [[nodiscard]] Node getHead() const;

    //Get the last element in the list
    [[nodiscard]] Node getTail() const;

    //Delete the first element in the list
    void deleteFirst();

    //Delete the last element in the list
    void deleteLast();

    //Add an element to the front of the list
    void addFirst(TElem element);

    //Add an element to the back of the list
    void addLast(TElem element);

    //Check if the list is empty
    [[nodiscard]] bool isEmpty() const;
};
