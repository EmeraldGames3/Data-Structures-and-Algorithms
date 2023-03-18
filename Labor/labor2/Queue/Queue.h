#pragma once
#include "../LinkedList/LinkedList.h"

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
#ifndef NULL_TELEM
#define NULL_TELEM -11111
#endif //NULL_TELEM

class Queue
{
private:
    DoubleLinkedList linkedList;

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
