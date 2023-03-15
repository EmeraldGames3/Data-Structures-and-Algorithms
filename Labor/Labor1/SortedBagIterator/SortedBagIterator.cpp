#include "SortedBagIterator.h"
#include "../SortedBag/SortedBag.h"
#include <exception>

using namespace std;

/**
 * @param b A SortedBag
 * @complexity θ(1)
 */
SortedBagIterator::SortedBagIterator(const SortedBag &b) : bag(b) { this->current = 0; }

/**
 * @return The element corresponding to the current value of the iterator
 * @throws exception If the iterator is not valid throw an exception
 * @complexity θ(1)
 */
TComp SortedBagIterator::getCurrent() {
    if (!valid()) throw exception(); // if the iterator is not valid, throw an exception
    return this->bag.dynamicArray[current];
}

/**
 * @return  True if the iterator is valid, false otherwise
 * @complexity θ(1)
 */
bool SortedBagIterator::valid() {
    if (this->bag.isEmpty()) return false;
    if (this->current < 0 || this->current >= this->bag.length) return false;
    return true;
}

/**
 * Put the iterator on the next position
 * @complexity θ(1)
 */
void SortedBagIterator::next() {
    if (this->current == this->bag.length) throw exception();
    this->current++;
}

/**
 * Put the iterator on the first element of the array
 * @throws exception If the bag is empty
 * @complexity θ(1)
 */
void SortedBagIterator::first() {
    if (this->bag.isEmpty()) throw exception();
    this->current = 0;
}