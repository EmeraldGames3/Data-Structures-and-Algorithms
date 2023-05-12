#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag &c) : bag(c) {
    current = 0;
    currentFrequency = bag.dynamicArray[0].second;
}

void BagIterator::first() {
    if(bag.isEmpty())
        throw exception();
    current = 0;
    currentFrequency = bag.dynamicArray[0].second;
}

void BagIterator::next() {
    if (current == bag.length)
        throw exception();

    if(currentFrequency == 1){
        current++;
        currentFrequency = bag.dynamicArray[current].second;
    } else{
        currentFrequency--;
    }
}

bool BagIterator::valid() const {
    if (bag.isEmpty())
        return false;
    if (current < 0 || current >= bag.arrayLength)
        return false;
    return true;
}

TElem BagIterator::getCurrent() const {
    if(!valid())
        throw exception();
    return bag.dynamicArray[current].first;
}
