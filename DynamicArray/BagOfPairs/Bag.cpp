#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>

using namespace std;


Bag::Bag() {
    length = 0;
    capacity = 10;
    dynamicArray = new pair<TElem, int>[capacity];
}


void Bag::add(TElem elem) {

}


bool Bag::remove(TElem elem) {

}

bool Bag::search(TElem elem) const {

}

int Bag::nrOccurrences(TElem elem) const {

}

int Bag::size() const {
    return length;
}

bool Bag::isEmpty() const {
    return length == 0;
}

BagIterator Bag::iterator() const {
    return BagIterator(*this);
}

Bag::~Bag() {
    delete[] dynamicArray;
}

void Bag::resize(int newCapacity) {
//    if (newCapacity < length)
//        throw std::out_of_range("Index out of range");
//
//    auto *newArray = new TElem[newCapacity];
//    for (size_t i = 0; i < length; i++)
//        newArray[i] = dynamicArray[i];
//
//    delete[] dynamicArray;
//    dynamicArray = newArray;
//    capacity = newCapacity;
}

void Bag::automaticResize() {
    if (length == capacity)
        resize(capacity * 2);
    if (length <= capacity / 4 && capacity >= 10)
        resize(capacity / 2);
}