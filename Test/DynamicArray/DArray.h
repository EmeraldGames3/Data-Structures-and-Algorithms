#ifndef DYNAMICARRAY_DARRAY_H
#define DYNAMICARRAY_DARRAY_H

#include <iostream>

template<typename type>

class DArray {
private:
    type *array;
    size_t length{};
    size_t capacity{};

    void automaticResize();

public:
    //constructor with 0 parameters
    explicit DArray();

    //constructor with 1 parameter
    explicit DArray(size_t _length);

    //constructor with 2 parameters
    DArray(size_t _length, type *array);

    //constructor with 3 parameters
    DArray(size_t _length, size_t _capacity, type *array);

    //Class destructor
    ~DArray();

    size_t size();

    void resize(size_t newCapacity);

    type getElement(size_t index);

    void setElement(size_t index, type value);

    void addToEnd(type value);

    void addToPosition(size_t index,type value);

    void deleteFromEnd();

    void deleteFromPosition(size_t index);
};


#endif //DYNAMICARRAY_DARRAY_H