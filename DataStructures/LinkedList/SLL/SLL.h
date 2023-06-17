#pragma once


typedef int TElem;
#define NULL_TELEM (-11111);

class SLLIterator;

struct SLLNode {
    TElem info;
    SLLNode *next;
};

class SLL {
    friend class SLLIterator;

private:
    SLLNode *head;
    int size;

public:
    SLL();

    void addFirst(TElem element);

    void AddBeforeNode(SLLNode *currentNode, TElem element);

    void addAfterNode(SLLNode *currentNode, TElem element);

    void insertPosition(int position, TElem element);

    TElem deleteFirst();

    TElem deleteElement(TElem element);

    [[nodiscard]] int getSize() const;

    [[nodiscard]] bool isEmpty() const;

    SLLIterator getIterator();

    ~SLL();
};