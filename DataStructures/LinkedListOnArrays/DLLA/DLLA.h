#pragma once

typedef int TElem;

#define NULL_TELEM (-11111);

class DLLAIterator;

struct DLLANode {
    TElem info;
    int next;
    int previous;
};

class DLLA {
    friend class DLLAIterator;

private:
    int capacity, head, tail, firstEmpty, size;
    DLLANode *array;

public:
    DLLA();

    ~DLLA();

    void addToStart(TElem elem);

    TElem removeFromStart();

    DLLAIterator getIterator();
};