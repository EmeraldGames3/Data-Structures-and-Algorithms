#include "ExtendedIterator.h"
#include <exception>

/**
 * Class constructor
 * @param b A sorted bag
 * @param position A valid position in the array
 * @complexity θ(1)
 * @throws exception if the position is invalid
 */
ExtendedSortedBagIterator::ExtendedSortedBagIterator(const SortedBag &b, int position) : bag(b) {
    if (!bag.search(position)) //Invalid position
        throw std::exception();

    current = position;
}

/**
 * @return Return the element that corresponds to the
 * @complexity θ(1)
 * @throws exception if the iterator is invalid
 */
TComp ExtendedSortedBagIterator::getCurrent() {
    if (!valid())
        throw std::exception();
    return this->bag.dynamicArray[current];
}

/**
 * @return  True if the iterator is valid, false otherwise
 * @complexity θ(1)
 */
bool ExtendedSortedBagIterator::valid() {
    if (this->bag.isEmpty()) return false;
    if (this->current < 0 || this->current >= this->bag.length) return false;
    return true;
}

/**
 * Put the iterator on the next element of the array
 * @complexity θ(1)
 * @throws exception if the iterator has reached the last position in the array
 */
void ExtendedSortedBagIterator::next() {
    if (current == bag.length)
        throw std::exception();

    current++;
}

/**
 * Put the iterator on the previous element of the array
 * @complexity θ(1)
 * @throws exception if the iterator has reached the first position
 */
void ExtendedSortedBagIterator::first() {
    if (bag.isEmpty())
        throw std::exception();
    current = 0;
}

/**
 * @complexity θ(1)
 */
void ExtendedSortedBagIterator::previous() {
    if (current <= 0)
        throw std::exception();
    current--;
}
