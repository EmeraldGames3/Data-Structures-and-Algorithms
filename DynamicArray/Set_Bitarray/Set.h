#pragma once
#define NULL_TELEM -11111
typedef int TElem;
class SetIterator;

class Set {
    friend class SetIterator;

private:
    TElem minimumElement;
    int capacity;
    int nrElems;
    bool* bitArray;

public:
    //implicit constructor
    Set();

    // constructor copy
    Set(const Set& other);

    // intersection of 2 sets
    Set intersection(const Set &other) const;

    //adds an element to the set
    //returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
    bool add(TElem e);

    //removes an element from the set
    //returns true if e was removed, false otherwise
    bool remove(TElem e);

    //checks whether an element belongs to the set or not
    bool search(TElem elem) const;

    //returns the number of elements;
    int size() const;

    //check whether the set is empty or not;
    bool isEmpty() const;

    //return an iterator for the set
    SetIterator iterator() const;

    // destructor
    ~Set();

};