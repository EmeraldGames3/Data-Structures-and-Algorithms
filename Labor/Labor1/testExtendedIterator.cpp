#include "ShortTest.h"
#include "SortedBag.h"
#include "SortedBagIterator.h"
#include "ExtendedIterator.h"
#include <assert.h>
#include <iostream>
#include <exception>

using namespace std;

bool relation22(TComp r1, TComp r2) {
    return r1 <= r2;
}

bool relation33(TComp r1, TComp r2) {
    return r1 >= r2;
}

void testIterator2(Relation rel) {
    cout << "Test iterator" << endl;
    SortedBag sb(rel);
    for (int i = 0; i < 500; i++) {
        sb.add(i);
        sb.add(-2 * i);
        sb.add(2 * i);
        sb.add(i);
        sb.add(-2 * i);
        sb.add(2 * i);
    }

    assert(sb.size() == 3000);

    ExtendedSortedBagIterator sbi = sb.extendedIterator(0);
    int count = 0;
    while (sbi.valid()) {
        count++;
        sbi.next();
    }
    assert(count == sb.size());
    sbi.first();
    TElem e = sbi.getCurrent();
    sbi.next();
    count = 1;
    while (sbi.valid()) {
        TElem ee = sbi.getCurrent();
        assert(rel(e, ee));
        TElem ee2 = sbi.getCurrent();
        assert(ee == ee2);
        TElem ee3 = sbi.getCurrent();
        assert(ee == ee3);
        e = ee;
        sbi.next();
        count++;
    }
    assert(count == sb.size());


    ExtendedSortedBagIterator sbi2 = sb.extendedIterator(5);

    count = 5;
    while (sbi2.valid()) {
        count++;
        sbi2.next();
    }
    assert(count == sb.size());

    ExtendedSortedBagIterator sbi3 = sb.extendedIterator(5);
    count = 6;
    while (true) {
        count--;
        try{
            sbi3.previous();
        }
        catch (exception &) {
            break;
        }
    }
    assert(count == 0);
}

void testExtendedIterator() {
    testIterator2(relation22);
    testIterator2(relation33);
}
