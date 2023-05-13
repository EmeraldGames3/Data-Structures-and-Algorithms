#pragma once
#include <vector>
using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM -11111

class Queue
{
private:
	//TODO - Representation
    int capacity;
    int front;
    int rear;
    TElem* queue;

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

    TElem print_helper();

	//checks if the queue is empty
	bool isEmpty() const;

    //resize the array when it's full
    void resize_push();

    //resize the array when there are too few elements
    void resize_pop();

    //print the elements of the queue
    void print_queue();

	// destructor
	~Queue();
};
