#include "SortedBagIterator.h"
#include "../SortedBag/SortedBag.h"
#include <exception>

using namespace std;

/**
 * @param b A SortedBag
 * @complexity θ(1)
 */
SortedBagIterator::SortedBagIterator(const SortedBag &b) : bag(b) { current = 0; }

/**
 * @return The element corresponding to the current value of the iterator
 * @throws exception If the iterator is not valid throw an exception
 * @complexity θ(1)
 */
TComp SortedBagIterator::getCurrent() {
    if (!valid()) throw exception(); // if the iterator is not valid, throw an exception
    return bag.dynamicArray[current];
}

/**
 * @return  True if the iterator is valid, false otherwise
 * @complexity θ(1)
 */
bool SortedBagIterator::valid() {
    if (bag.isEmpty()) return false;
    if (current < 0 || current >= bag.length) return false;
    return true;
}

/**
 * Put the iterator on the next position
 * @complexity θ(1)
 */
void SortedBagIterator::next() {
    if (current == bag.length) throw exception();
    current++;
}

/**
 * Put the iterator on the first element of the array
 * @throws exception If the bag is empty
 * @complexity θ(1)
 */
void SortedBagIterator::first() {
    if (bag.isEmpty()) throw exception();
    current = 0;
}

