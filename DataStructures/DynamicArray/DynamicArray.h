#pragma once
#include <cstddef>
#define NULL_TELEM (-111111)
typedef int TElem;

class DynamicArrayIterator;

class DynamicArray {
    ///Iterator
    friend class DynamicArrayIterator;

private:
    size_t size, capacity;
    TElem *array;

    ///Resize the array
    void resize(size_t newCapacity);
    void automaticResize();

public:
    ///Constructor
    DynamicArray();

    ///Get the size of the array
    [[nodiscard]] int getSize() const;
    [[nodiscard]] bool isEmpty() const;

    ///Get an element
    TElem getElementWithPosition(size_t position);
    TElem getElement(TElem element);

    ///Set the value of an element
    TElem setElement(size_t position, TElem newElement);

    ///Add an element to the array
    void addToPosition(size_t position, TElem element);
    void addToStart(TElem element);
    void addToEnd(TElem element);

    ///Remove an element from the array
    TElem removeElementPosition(size_t position);
    TElem removeElement(TElem element);
    TElem removeFromStart();
    TElem removeFromEnd();

    ///Get an iterator
    DynamicArrayIterator getIterator();

    ///Destructor
    ~DynamicArray();
};