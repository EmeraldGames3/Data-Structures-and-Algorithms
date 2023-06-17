#include "DynamicArray.h"
#include "DynamicArrayIterator.h"
#include <stdexcept>

DynamicArray::DynamicArray() {
    size = 0;
    capacity = 10;
    array = new TElem[capacity];
}

DynamicArray::~DynamicArray() {
    size = 0;
    capacity = 0;
    delete[] array;
}

DynamicArrayIterator DynamicArray::getIterator() {
    return DynamicArrayIterator(*this);
}

void DynamicArray::resize(size_t newCapacity) {
    if (newCapacity < size)
        throw std::invalid_argument("New size is smaller than the actual size");

    auto *newArray = new TElem[newCapacity];

    for (size_t i = 0; i < size; i++) {
        newArray[i] = array[i];
    }

    delete[] this->array;
    this->array = newArray;
    this->capacity = newCapacity;
}

void DynamicArray::automaticResize() {
    if (this->size >= this->capacity)
        resize(this->capacity * 2);
    if (this->size <= this->capacity / 4 && this->capacity >= 10)
        resize(this->capacity / 2);
}

int DynamicArray::getSize() const {
    return static_cast<int>(size);
}

bool DynamicArray::isEmpty() const {
    return size == 0;
}

TElem DynamicArray::getElement(TElem element) {
    for (size_t i = 0; i < size; i++) {
        if (array[i] == element) {
            return array[i];
        }
    }

    return NULL_TELEM;
}

TElem DynamicArray::getElementWithPosition(size_t position) {
    if (position >= size)
        throw std::invalid_argument("Invalid size");
    return array[position];
}

TElem DynamicArray::setElement(size_t position, TElem newElement) {
    if (position >= size)
        throw std::invalid_argument("Invalid position");

    TElem oldValue = array[position];
    array[position] = newElement;

    return oldValue;
}

void DynamicArray::addToPosition(size_t position, TElem element) {
    if (size == 0) {
        addToStart(element);
        return;
    }

    if (position > size)
        throw std::invalid_argument("Invalid position");

    // Move elements from position to the right
    for (size_t i = size; i > position; i--) {
        array[i] = array[i - 1];
    }

    // Insert the new element at the specified position
    array[position] = element;
    size++;

    automaticResize();
}

void DynamicArray::addToStart(TElem element) {
    if (size == 0) {
        array[0] = element;
        size = 1;
        return;
    }

    for (size_t i = size; i > 0; i--) {
        array[i] = array[i - 1];
    }

    array[0] = element;
    size++;
    automaticResize();
}

void DynamicArray::addToEnd(TElem element) {
    if (size == 0) {
        array[0] = element;
        size = 1;
        return;
    }

    array[size] = element;
    size++;
    automaticResize();
}

TElem DynamicArray::removeElement(TElem element) {
    if (isEmpty())
        throw std::invalid_argument("Array is empty");
    automaticResize();

    for (size_t i = 0; i < size; i++) {
        if (element == array[i]) {
            return removeElementPosition(i);
        }
    }

    return NULL_TELEM;
}

TElem DynamicArray::removeElementPosition(size_t position) {
    if (position >= size)
        throw std::invalid_argument("Invalid position");

    TElem oldValue = array[position];

    // Move elements from position + 1 to the left
    for (size_t i = position; i < size - 1; i++) {
        array[i] = array[i + 1];
    }

    size--;
    automaticResize();
    return oldValue;
}

TElem DynamicArray::removeFromEnd() {
    automaticResize();
    TElem oldValue = array[size - 1];
    size--;
    automaticResize();
    return oldValue;
}

TElem DynamicArray::removeFromStart() {
    automaticResize();
    return removeElementPosition(0);
}