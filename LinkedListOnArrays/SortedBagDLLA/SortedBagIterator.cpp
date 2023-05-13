#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>
#include <iostream>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag &b) : bag(b) {
    //TODO - Implementation
    currentElement = bag.head;
}

TComp SortedBagIterator::getCurrent() {
    //TODO - Implementation
    if (!valid())
        throw invalid_argument("");
    return bag.nodes[currentElement].info;

}

bool SortedBagIterator::valid() {
    //TODO - Implementation
    if (currentElement != -1)
        return true;
    return false;
}

void SortedBagIterator::next() {
    //TODO - Implementation
    if (valid())
        currentElement = bag.nodes[currentElement].next;
    else {
        throw invalid_argument("");
    }
}

void SortedBagIterator::first() {
    //TODO - Implementation
    if (bag.head != -1)
        currentElement = bag.head;
    else {
        throw invalid_argument("");
    }
}

