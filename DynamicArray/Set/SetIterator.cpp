#include "SetIterator.h"
#include "Set.h"


SetIterator::SetIterator(const Set &m) : set(m) {
    //TODO - Implementation
    if (!m.isEmpty()) {
        iterator = 0;
    }
}


void SetIterator::first() {
    //TODO - Implementation
    if (valid())
        iterator = 0;

}


void SetIterator::next() {
    //TODO - Implementation
    if(valid())
        iterator++;

}


TElem SetIterator::getCurrent() {
    //TODO - Implementation
    return set.set[iterator];
}

bool SetIterator::valid() const {
    //TODO - Implementation
    if (!set.isEmpty() and iterator < set.current_size)
        return true;
    return false;
}



