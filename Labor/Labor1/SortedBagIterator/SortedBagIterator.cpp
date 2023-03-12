#include "SortedBagIterator.h"
#include "../SortedBag/SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag &b) : bag(b) {
    current = 0;
}

TComp SortedBagIterator::getCurrent() {
    if (!valid()) throw exception(); // if the iterator is not valid, throw an exception
    return bag.dynamicArray[current];
}

bool SortedBagIterator::valid() {
    if(bag.isEmpty())
        return false;
    if(current < 0 || current >= bag.length)
        return false;
    return true;
}

void SortedBagIterator::next() {
    if (current == bag.length) throw exception();
    current++;
}

void SortedBagIterator::first() {
    if (bag.isEmpty()) throw exception();
    current = 0;
}

