#include <stdexcept>
#include "CoalescedChainingIterator.h"

CoalescedChainingIterator::CoalescedChainingIterator(const CoalescedChaining &t) : table(t) {
    currentPosition = 0;

    while(currentPosition < table.capacity && table.table[currentPosition] == NULL_TKEY)
        currentPosition++;
}

void CoalescedChainingIterator::first() {
    currentPosition = 0;

    while(currentPosition < table.capacity && table.table[currentPosition] == NULL_TKEY)
        currentPosition++;
}

void CoalescedChainingIterator::next() {
    if(!valid())
        throw std::invalid_argument("Invalid position in hash table!");

    while (currentPosition < table.capacity && table.table[currentPosition] == NULL_TKEY) {
        currentPosition++;
    }
}

bool CoalescedChainingIterator::valid() {
    return(currentPosition >= 0 && currentPosition < table.capacity);
}

TKey CoalescedChainingIterator::getCurrent() {
    if(valid()) {
        return table.table[currentPosition];
    }

    throw std::invalid_argument("Invalid element in the table!");
}
