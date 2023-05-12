#pragma once
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
typedef int TElem;
class BagIterator; 
class Bag {

private:
    int length;
    int capacity;
    TElem *dynamicArray;

    //Resize the dynamicArray
    void resize(int newCapacity);

    //Automatically resize the dynamicArray
    void automaticResize();


	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	[[nodiscard]] bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	[[nodiscard]] int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	[[nodiscard]] int size() const;

	//returns an iterator for this bag
	[[nodiscard]] BagIterator iterator() const;

	//checks if the bag is empty
	[[nodiscard]] bool isEmpty() const;

	//destructor
	~Bag();
};