#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>

ListIterator::ListIterator(const IteratedList &list) : list(list) {
    current = list.head;
}

void ListIterator::first() {
    current = list.head;
}

void ListIterator::next() {
    if (!valid())
        throw std::exception();

    current = list.array[current].next;
}

bool ListIterator::valid() const {
    if (current == -1)
        return false;
    return true;
}

TElem ListIterator::getCurrent() const {
    return list.array[current].value;
}



