#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap &m) : map(m) {
    currentNode = map.head;
}

void SMIterator::first() {
    currentNode = map.head;
}

void SMIterator::next() {
    if (!valid())
        throw exception();

    currentNode = currentNode->next;
}

bool SMIterator::valid() const {
    return currentNode != nullptr;
}

TElem SMIterator::getCurrent() const {
    if(!valid())
        throw exception();

    return TElem{currentNode->key, currentNode->value};
}


