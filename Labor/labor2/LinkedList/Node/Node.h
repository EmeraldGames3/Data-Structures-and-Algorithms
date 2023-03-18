#pragma once

typedef int TElem;

class Node{
private:
    TElem element;
    Node *nextNode;
    Node *previousNode;

public:
    Node();

    explicit Node(TElem elem);

    Node(TElem elem, Node *next, Node * previous);

    Node(Node const &other);

    [[nodiscard]] TElem getElement() const;

    void setElement(TElem elem);

    [[nodiscard]] Node *next() const;

    void setNextNode(Node *node);

    [[nodiscard]] Node *previous() const;

    void setPreviousNode(Node *node);

    ~Node();
};