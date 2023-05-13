#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

BagIterator::BagIterator(const Bag &c) : bag(c) {
    if(bag.isEmpty()){
        index = 0;
        frequency = 0;
        return;
    }

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

    frequency--;
    if(frequency == 0){
        index++;

        if(!valid())
            return;

        while (bag.array[index] == 0){
            index++;
        }
        frequency = bag.array[index];
    }
}

bool BagIterator::valid() const {
    if(bag.size() == 0)
        return false;

    if (index < 0 || index == bag.maximumElement - bag.minimumElement + 1)
        return false;
    return true;
}

TElem BagIterator::getCurrent() const {
    return bag.minimumElement + index;
}
