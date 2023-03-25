#pragma once
#include "Location.h"

typedef Location TElem;
#define NULL_TELEM Location();

struct Node{
    TElem info;
    Node *previous;
    Node *next;

    //Constructor with implicit parameters
    explicit Node(TElem _info = Location(-1,-1), Node *_previous = nullptr, Node *_next = nullptr);
};

class Queue{
private:
    Node *head;
    Node *tail;

public:
	Queue();

	//pushes an element to the end of the queue
	void push(const TElem& e);

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
