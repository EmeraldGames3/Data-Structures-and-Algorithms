#pragma once
#include "Location/Location.h"

typedef Location TElem;
#define NULL_TELEM Location();

struct Node{
    TElem info;
    Node *previous;
    Node *next;

    Node();
    //Constructor with implicit parameters
    explicit Node(const TElem& _info, Node *_previous, Node *_next);
};

class LocationQueue{
private:
    Node *head;
    Node *tail;

public:
    //Default constructor
	LocationQueue();

    //Copy constructor
    LocationQueue(const LocationQueue &other);

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
	~LocationQueue();

    //Overload the = operator
    LocationQueue &operator=(const LocationQueue &other);
};
