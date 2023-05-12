#include "SetIterator.h"
#include "Set.h"

SetIterator::SetIterator(const Set &m) : set(m) {
    // we call first to find the first element in the array
    first();
}

/// minimum complexity: tetha(1) - the first element of the set is true
/// maximum complexity: tetha(arraySize) - there are no true values in the array or the true value is towards the end of the array
void SetIterator::first() {
    // after executing first(), index will point to the first true value from array
    index = 0;
    while (valid() && !set.bitArray[index])
        index++;
}

/// minimum complexity tetha(1), maximum complexity tetha(arraySize)
void SetIterator::next() {
    index++;
    while (valid()) {
        // if we find an element in the set whose value is true, we stop the loop
        if (set.bitArray[index])
            break;
        index++;
    }
}

/// complexity: tetha(1)
TElem SetIterator::getCurrent() {
    return index + set.minimumElement;
}

/// complexity: tetha(1)
bool SetIterator::valid() const {
    if(this->index >= 0 && this->index < set.capacity)
        return true;
    return false;
}