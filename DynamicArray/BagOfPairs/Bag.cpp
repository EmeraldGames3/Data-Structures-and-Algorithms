#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>

using namespace std;

Bag::Bag() {
    length = 0;
    arrayLength = 0;
    capacity = 10;
    dynamicArray = new pair<TElem, int>[capacity];
}

void Bag::add(TElem elem) {
    for(int i = 0; i < arrayLength; i++){
        if(dynamicArray[i].first == elem){
            dynamicArray[i].second++;
            length++;
            return;
        }
    }
    dynamicArray[arrayLength] = make_pair(elem, 1);
    length++;
    arrayLength++;
    automaticResize();
}

bool Bag::remove(TElem elem) {
    for(int i = 0; i < arrayLength; i++){
        if(dynamicArray[i].first == elem){
            if(dynamicArray[i].second == 1){
                dynamicArray[i] = dynamicArray[length - 1];
                arrayLength--;
                automaticResize();
            } else{
                dynamicArray[i].second--;
            }
            length--;
            return true;
        }
    }
    return false;
}

bool Bag::search(TElem elem) const {
    for (int i = 0; i < arrayLength; i++) {
        if (dynamicArray[i].first == elem)
            return true;
    }
    return false;
}

int Bag::nrOccurrences(TElem elem) const {
    for (int i = 0; i < arrayLength; i++) {
        if (dynamicArray[i].first == elem)
            return dynamicArray[i].second;
    }
    return 0;
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
    if (newCapacity < length)
        throw std::out_of_range("Index out of range");

    auto *newArray = new pair<TElem, int>[newCapacity];
    for (size_t i = 0; i < length; i++)
        newArray[i] = dynamicArray[i];

    delete[] dynamicArray;
    dynamicArray = newArray;
    capacity = newCapacity;
}

void Bag::automaticResize() {
    if (arrayLength == capacity)
        resize(capacity * 2);
    if (arrayLength <= capacity / 4 && capacity >= 10)
        resize(capacity / 2);
}