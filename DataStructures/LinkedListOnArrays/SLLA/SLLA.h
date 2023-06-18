#pragma once

class SLLAIterator;
typedef int TElem;
#define NULL_TELEM (-11111);

struct SLLANode{
    TElem info;
    int next;
};

class SingleLinkedListOnArrays{
    friend class SLLAIterator;

private:
    SLLANode *array;
    int size;
    int capacity;
    int head;
    int firstEmpty;

public:
    SingleLinkedListOnArrays();

    ~SingleLinkedListOnArrays();

    void addToStart(TElem element);

    void addToPosition(int position, TElem elem);

    TElem removeFromStart();
    TElem removeElement(TElem element);
    TElem removeFromPosition(int position);

    [[nodiscard]] SLLAIterator getIterator() const;
};