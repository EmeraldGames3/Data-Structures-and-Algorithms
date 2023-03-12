#pragma once
#include "DynamicArrayIterator.h"

//TODO: Add documentation
template<typename type>
DynamicArrayIterator<type>::DynamicArrayIterator(const DynamicArray<type> &_dynamicArray) {
    currentPosition = 0;
    dynamicArray = _dynamicArray;
}

//TODO: Add documentation
template<typename type>
void DynamicArrayIterator<type>::first() {
    currentPosition = 0;
}

//TODO: Add documentation
template<typename type>
void DynamicArrayIterator<type>::next() {
    if(currentPosition == dynamicArray.length) throw std::out_of_range("Index out of range");
    currentPosition++;
}

//TODO: Add documentation
template<typename type>
bool DynamicArrayIterator<type>::valid() {
    if(dynamicArray.inRange(currentPosition)) return true;
    return false;
}