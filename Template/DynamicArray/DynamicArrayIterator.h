#pragma once

#include "DynamicArray.h"
#include "DynamicArray.cpp"

//TODO: Add documentation
template<typename type>
class DynamicArrayIterator{
    friend class DynamicArray<type>;

private:
    const DynamicArray<type> &dynamicArray;
    int currentPosition{};

    explicit DynamicArrayIterator(const DynamicArray<type> &_dynamicArray);

public:
    bool valid();
    void next();
    void first();
};
