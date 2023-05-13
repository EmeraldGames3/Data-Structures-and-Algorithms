#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>

using namespace std;

Bag::Bag() {
    capacity = 1;
    array = new int[capacity];
    minimumElement = 0;
    maximumElement = 0;
    nrElems = 0;
    minimumElement = NULL_TELEM;
}

void Bag::add(TElem elem) {
    if (nrElems == 0) {
        array[0] = 1;
        minimumElement = elem;
        maximumElement = elem;
        nrElems = 1;
        return;
    }

    if (elem >= minimumElement && elem < maximumElement) {
        array[elem - minimumElement]++;
        nrElems++;
        return;
    }

    if (elem < minimumElement) {
        int shiftingSize = minimumElement - elem;
        int newCapacity = capacity + shiftingSize;
        int *newArray = new int[newCapacity];

        newArray[0] = 1;

        for (int i = 1; i < shiftingSize; i++)
            newArray[i] = 0;

        for (int i = 0; i < capacity; i++)
            newArray[i + shiftingSize] = array[i];

        delete[] array;

        array = newArray;
        capacity = newCapacity;
        minimumElement = elem;
        nrElems++;
        return;
    }

    int newMaximumElement = minimumElement + capacity - 1;
    int newArraySize = capacity + (elem - newMaximumElement);
    int *auxiliaryArray = new int [newArraySize];

    // copy the old array
    for (int i = 0; i < capacity; i++)
        auxiliaryArray[i] = array[i];
    for (int i = capacity; i < newArraySize - 1; i++)
        auxiliaryArray[i] = 0;
    // add elem
    auxiliaryArray[newArraySize - 1] = true;
    //delete the old array
//    delete[] array;

    // update the pointer to the array and the size
    array = auxiliaryArray;
    capacity = newArraySize;
    nrElems++;
    maximumElement = elem;
}

bool Bag::remove(TElem elem) {
    if(size() == 0){
        return false;
    }

    if(elem >= minimumElement && elem <= maximumElement){
        if(array[elem - minimumElement] == 0){
            return false;
        }
        array[elem - minimumElement]--;
        nrElems--;
        return true;
    }

    //resize down if needed

    return false;
}

bool Bag::search(TElem elem) const {
    if(size() == 0){
        return false;
    }
    if (elem < minimumElement || elem > maximumElement)
        return false;

    return true;
}

int Bag::nrOccurrences(TElem elem) const {
    if(size() == 0){
        return 0;
    }

    if (elem < minimumElement || elem > maximumElement) {
        return 0;
    }
    return array[elem - minimumElement];
}

int Bag::size() const {
    return nrElems;
}

bool Bag::isEmpty() const {
    return nrElems == 0;
}

BagIterator Bag::iterator() const {
    return {*this};
}

Bag::~Bag() {
    delete[] array;
}

