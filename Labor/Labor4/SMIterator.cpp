#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

/**
* @brief Iterator constructor
* @complexity θ(1)
*/
SMIterator::SMIterator(const SortedMap &m) : map(m) {
    currentNode = map.head;
}

/**
* @brief Set the iterator on the first position
* @complexity θ(1)
*/
void SMIterator::first() {
    currentNode = map.head;
}

/**
* @brief Set the iterator on the next element
* @complexity θ(1)
* @throws exception if the iterator is invalid
*/
void SMIterator::next() {
    if (!valid())
        throw exception();

    currentNode = currentNode->next;
}

/**
* @brief Check if the iterator is valid
* @complexity θ(1)
*/
bool SMIterator::valid() const {
    return currentNode != nullptr;
}

/**
* @brief Get the current (TKey, TValue) pair
* @complexity θ(1)
* @throws exception if the iterator is invalid
*/
TElem SMIterator::getCurrent() const {
    if(!valid())
        throw exception();

    return TElem{currentNode->key, currentNode->value};
}