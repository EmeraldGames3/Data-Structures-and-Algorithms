#pragma once
//DO NOT INCLUDE LISTITERATOR

//DO NOT CHANGE THIS PART
class ListIterator;
typedef int TComp;
typedef bool (*Relation)(TComp, TComp);
#define NULL_TCOMP -11111

struct Node{
    TComp value;
    Node *parent;
    Node *left;
    Node *right;
    int nrLeftElements;
};

class SortedIndexedList {
private:
	friend class ListIterator;
private:
	int nrElems;
    Node *head;
    Relation relation;

public:
    // constructor
    explicit SortedIndexedList(Relation r);

    // returns the size of the list
    [[nodiscard]] int size() const;

    //checks if the list is empty
    [[nodiscard]] bool isEmpty() const;

    // returns an element from a position
    //throws exception if the position is not valid
    [[nodiscard]] TComp getElement(int pos) const;

    // adds an element to a given position
    //throws an exception if the position is not valid
    void add(TComp e);

    // removes an element from a given position
    //returns the removed element
    //throws an exception if the position is not valid
    TComp remove(int pos);

    void deleteKElement(int k);

    // searches for an element and returns the first position where the element appears or -1 if the element is not in the list
    [[nodiscard]] int search(TComp e) const;

    // returns an iterator set to the first element of the list or invalid if the list is empty
    ListIterator iterator();

    //destructor
    ~SortedIndexedList();
};
