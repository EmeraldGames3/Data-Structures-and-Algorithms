#ifndef DYNAMICARRAY_DYNAMICARRAY_H
#define DYNAMICARRAY_DYNAMICARRAY_H

#include <iostream>

template<typename type>

class DynamicArray {
private:
    type *array;
    size_t length{};
    size_t capacity{};

    void automaticResize();

public:
    DynamicArray();

    DynamicArray(size_t _length, type *array);

    DynamicArray(size_t _length, size_t _capacity, type *array);

    size_t size();

    void resize(size_t newCapacity);

    type getElement(size_t index);

    void setElement(size_t index, type value);

    void addToEnd(type value);

    void addToPosition(size_t index, type value);

    void deleteFromEnd();

    void deleteFromPosition(size_t index);
};


#endif //DYNAMICARRAY_DYNAMICARRAY_H