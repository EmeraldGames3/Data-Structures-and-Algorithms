#pragma once

#include <vector>

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM -11111

struct Node {
    int data;
    int next;
    int previous;
};

class Queue {
private:
    Node* arr;
    int head;
    int tail;
    int size;
    int capacity;

public:
    Queue();

    //pushes an element to the end of the queue
    void push(TElem e);

    //returns the element from the front of the queue
    //throws exception if the queue is empty
    TElem top() const;

    //removes and returns the element from the front of the queue
    //throws exception if the queue is empty
    TElem pop();

    //checks if the queue is empty
    bool isEmpty() const;

    // destructor
    ~Queue();
};
