#include <assert.h>

#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

bool relation1(TComp e1, TComp e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedIndexedList list = SortedIndexedList(relation1);
	assert(list.size() == 0);
	assert(list.isEmpty());
    list.add(1);
    assert(list.size() == 1);
    assert(!list.isEmpty());
    ListIterator iterator = list.iterator();
    assert(iterator.valid());
    iterator.first();
    assert(iterator.getCurrent() == 1);
    iterator.next();
    assert(!iterator.valid());
    iterator.first();
    assert(iterator.valid());
    assert(list.search(1) == 0);
    assert(list.remove(0) == 1);
    assert(list.size() == 0);
    assert(list.isEmpty());

    list.add(10);
    list.add(12);
    list.add(0);
    list.add(11);
    list.add(1);

    iterator.first();
    while (iterator.valid()){
        cout << iterator.getCurrent() << ' '
        << list.search(iterator.getCurrent())
        << '\n';
        iterator.next();
    }

    cout << '\n';
}