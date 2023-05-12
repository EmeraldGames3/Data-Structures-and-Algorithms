#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>

using namespace std;

Bag::Bag() {
	length = 0;
    capacity = 10;
    dynamicArray = new TElem[capacity];
}

void Bag::add(TElem elem) {
	dynamicArray[length] = elem;
    length++;
    automaticResize();
}

bool Bag::remove(TElem elem) {
	for(int i = 0; i < length; i++){
        if(elem == dynamicArray[i]){
            dynamicArray[i] = dynamicArray[length - 1];
            length--;
            automaticResize();
            return true;
        }
    }
	return false; 
}

bool Bag::search(TElem elem) const {
    for(int i = 0; i < length; i++)
        if(elem == dynamicArray[i])
            return true;
	return false; 
}

int Bag::nrOccurrences(TElem elem) const {
	int counter = 0;

    for(int i = 0; i < length; i++){
        if(elem == dynamicArray[i]){
            counter++;
        }
    }

	return counter;
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

    auto *newArray = new TElem[newCapacity];
    for (size_t i = 0; i < length; i++)
        newArray[i] = dynamicArray[i];

    delete[] dynamicArray;
    dynamicArray = newArray;
    capacity = newCapacity;
}

void Bag::automaticResize() {
    if (length == capacity)
        resize(capacity * 2);
    if (length <= capacity / 4 && capacity >= 10)
        resize(capacity / 2);
}