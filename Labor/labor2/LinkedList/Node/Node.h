#pragma once

typedef int TElem;
#ifndef NULL_TELEM
#define NULL_TELEM (-11111)
#endif //NULL_TELEM

class Node{
private:
    TElem element;
    Node *previousNode;
    Node *nextNode;

public:
    //Default constructor
    Node();

    //Constructor with 1 parameter
    explicit Node(TElem elem);

    //Constructor with 3 parameters
    Node(TElem elem, Node *previous, Node * next);

    //Copy constructor
    Node(Node const &other);

    //Create a NULL_NODE
    static Node NULL_NODE();

    //Check if a Node is NULL_NODE
    [[nodiscard]] bool isNULL() const;

    //element getter
    [[nodiscard]] TElem getElement() const;

    //element setter
    void setElement(TElem elem);

    //nextNode getter
    [[nodiscard]] Node *next() const;

    //nextNode setter
    void setNext(Node *node);

    //previousNode getter
    [[nodiscard]] Node *previous() const;

    //previousNode setter
    void setPrevious(Node *node);

    bool operator==(Node &other);

    ~Node();
};