#include <assert.h>

#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

bool relation1(TComp e1, TComp e2) {
    if (e1 <= e2) {
        return true;
    } else {
        return false;
    }
}

void testAll() {
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

    list.add(5);
    for (int i = 0; i < 10; i++) {
        if (i != 5)
            list.add(i);
    }

//    iterator.first();
//    while (iterator.valid()) {
//        cout << iterator.getCurrent() << ' ' << list.search(iterator.getCurrent()) << '\n';
//        iterator.next();
//    }

//    cout << '\n';

    list.deleteKElement(1);
    assert(list.size() == 1);
    list.deleteKElement(0);
    assert(list.isEmpty());

    list.add(3);
    list.add(0);
    list.add(1);
    list.add(2);
    list.add(4);
    list.add(5);
    list.add(6);
    list.add(7);
    list.add(8);
    list.add(9);
    assert(list.size() == 10);

    list.deleteKElement(2);
    assert(list.size() == 6);
    iterator.first();
    while (iterator.valid()) {
        assert(iterator.getCurrent() % 2 != 0 || iterator.getCurrent() == 0);
        cout << iterator.getCurrent() << ' ' << list.search(iterator.getCurrent()) << '\n';
        iterator.next();
    }

    cout << '\n';

    list.deleteKElement(2);
    assert(list.size() == 4);

    iterator.first();
    while (iterator.valid()) {
        cout << iterator.getCurrent() << ' ' << list.search(iterator.getCurrent()) << '\n';
        iterator.next();
    }

    list.deleteKElement(2);
    assert(list.size() == 3);
    cout << '\n';
    iterator.first();
    while (iterator.valid()) {
        cout << iterator.getCurrent() << ' ' << list.search(iterator.getCurrent()) << '\n';
        iterator.next();
    }

    list.deleteKElement(2);
    assert(list.size() == 2);
    cout << '\n';
    iterator.first();
    while (iterator.valid()) {
        cout << iterator.getCurrent() << ' ' << list.search(iterator.getCurrent()) << '\n';
        iterator.next();
    }

    cout << '\n';

    try {
        list.deleteKElement(2);
        assert(false);
    } catch (const exception &exception){
        assert(true);
    }

    list.deleteKElement(1);
    assert(list.size() == 1);
    list.deleteKElement(0);
    assert(list.isEmpty());
}