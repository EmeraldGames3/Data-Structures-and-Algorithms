#pragma once

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM -11111

struct StackNode{
    TElem info;
    StackNode *previous;
    StackNode *next;
};

class Stack{
private:
    StackNode *head;
    StackNode *tail;

public:
    Stack();

    //pushes an element to the end of the stack
    void push(TElem e);

    //returns the element from the end of the stack
    //throws exception if the stack is empty
    [[nodiscard]] TElem top() const;

    //removes and returns the element from the front of the stack
    //throws exception if the stack is empty
    TElem pop();

    //checks if the stack is empty
    [[nodiscard]] bool isEmpty() const;

    // destructor
    ~Stack();
};
