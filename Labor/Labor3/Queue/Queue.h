#pragma once

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM -11111

struct DLLANode {
    int data;
    int next;
    int previous;
};

class Queue {
public:
    DLLANode *array;
    int head;
    int tail;
    int size;
    int capacity;
    int firstEmpty;

public:
    //Resize the array to a new size
    void resize(int newCapacity);

    //Automatically resize the array
    void automaticResize();

    Queue();

    //pushes an element to the end of the queue
    void push(TElem e);

    //returns the element from the front of the queue
    //throws exception if the queue is empty
    [[nodiscard]] TElem top() const;

    //removes and returns the element from the front of the queue
    //throws exception if the queue is empty
    TElem pop();

    //checks if the queue is empty
    [[nodiscard]] bool isEmpty() const;

    // destructor
    ~Queue();
};
