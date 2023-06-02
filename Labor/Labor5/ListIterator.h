#pragma once
#include "SortedIndexedList.h"


//DO NOT CHANGE THIS PART
class ListIterator{
	friend class SortedIndexedList;
private:
	const SortedIndexedList& list;
	explicit ListIterator(const SortedIndexedList& list);
	Node *current;

public:
	void first();
	void next();
	[[nodiscard]] bool valid() const;
    [[nodiscard]] TComp getCurrent() const;
};


