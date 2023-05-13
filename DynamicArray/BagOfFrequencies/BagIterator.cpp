#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag &c) : bag(c) {
    index = 0;
    frequency = bag.array[0];
}

void BagIterator::first() {
    index = 0;
    frequency = bag.array[0];
}

void BagIterator::next() {
    if(!valid())
        throw exception();

    if(frequency == 1){
        index++;
        while (bag.array[index] == 0) {
            index++;
        }
        frequency = bag.array[index];
    } else{
        frequency--;
    }
}

bool BagIterator::valid() const {
    if(bag.size() == 0)
        return false;

    if (index < 0 || index == bag.capacity)
        return false;
    return true;
}

TElem BagIterator::getCurrent() const {
    return bag.minimumElement + index;
}
