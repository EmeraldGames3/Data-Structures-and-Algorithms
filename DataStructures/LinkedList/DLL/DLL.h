#pragma once

typedef int TElem;
#define NULL_TELEM (-11111)
class DLLIterator;

struct DLLNode{
    TElem info;
    DLLNode *next;
    DLLNode *previous;
};

class DLL{
    friend class DLLIterator;
private:
    DLLNode *head;
    DLLNode *tail;
    int size;

public:
    DLL();

    ~DLL();

    void addToPosition(int position, TElem elem);

    void addToStart(TElem elem);
    void addToEnd(TElem element);

    TElem removeStart();

    TElem removeElement(TElem element);

    bool isEmpty() const;

    int getSize() const;

    DLLIterator getIterator();
};