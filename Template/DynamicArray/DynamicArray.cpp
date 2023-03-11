#include "DynamicArray.h"

/**
 * @brief This is the default constructor of the class
 * @details It receives no parameters
 */
template<typename type>
DynamicArray<type>::DynamicArray() {
    length = 0;
    capacity = 0;
    array = nullptr;
}

/**
 * @brief This is a constructor of the class and receives two parameters
 * @param _length The length of the array
 * @param _array The array
 *
 * @detailsThe capacity of the array is equal to 2 * (length + 1)
 */
template<typename type>
DynamicArray<type>::DynamicArray(size_t _length, type *_array) {
    length = _length;
    capacity = 2 * (length + 1);
    array = new type[capacity];

    for (size_t i = 0; i < length; i++) {
        array[i] = _array[i];
    }
}

/**
 * @brief This is a constructor of the class and receives one parameters
 * @param _length The length of the array
 *
 * @detailsThe capacity of the array is equal to 2 * (length + 1)
 */
template<typename type>
DynamicArray<type>::DynamicArray(size_t _length) {
    length = _length;
    capacity = 2 * (length + 1);
    array = new type[capacity];
}

/**
 * @brief This is a constructor of the class and receives three parameters
 * @param _length The length of the dynamic array
 * @param _capacity The capacity of the new dynamic array
 * @param _array The array
 */
template<typename type>
DynamicArray<type>::DynamicArray(size_t _length, size_t _capacity, type *_array) {
    length = _length;
    capacity = _capacity;
    array = new type[capacity];

    for (size_t i = 0; i < length; i++) {
        array[i] = _array[i];
    }
}

/**
 * @brief This is the destructor of the class
 * @details Delete the dynamically allocated memory
 */
template<typename type>
DynamicArray<type>::~DynamicArray() {
    delete[] array;
}

/**
 * @return The current length of the array
 */
template<typename type>
size_t DynamicArray<type>::size() {
    return length;
}

/**
 * @brief Resizes the dynamic array to a new capacity
 *
 * @param newCapacity The new capacity of the array
 * @throws std::invalid_argument if the capacity of the array is less than the current length
 */
template<typename type>
void DynamicArray<type>::resize(size_t newCapacity) {
    if (newCapacity < length)
        throw std::invalid_argument("new capacity cannot be less than current length");

    capacity = newCapacity;

    type *newArray = new type[newCapacity];
    for (size_t i = 0; i < length; i++) {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray;
    capacity = newCapacity;
}

/**
 * @brief Automatically resizes the array to double its current capacity
 */
template<typename type>
void DynamicArray<type>::automaticResize() {
    capacity *= 2;

    type *newArray = new type[capacity];
    for (size_t i = 0; i < length; i++) {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray;
}

/**
 * @param index The index of the element
 * @return The Element at the received index
 */
template<typename type>
type DynamicArray<type>::getElement(size_t index) {
    if (index < 0 || index >= length)
        throw std::out_of_range("index out of range");

    return array[index];
}

/**
 * @brief Change the value of an element at a given index
 * @param index A number that corresponds to an index in the array
 * @param value The value to be added
 */
template<typename type>
void DynamicArray<type>::setElement(size_t index, type value) {
    if (index < 0 || index >= length)
        throw std::out_of_range("index out of range");

    array[index] = value;
}

/**
 * @brief Adds a new element to the end of the array
 * @details If the capacity of the array is not enough to add a new element, the array is resized to double its capacity
 *
 * @param value The value of the element to be added
 */
template<typename type>
void DynamicArray<type>::addToEnd(type value) {
    if (length == capacity)
        automaticResize();

    array[length++] = value;
}

/**
 * @brief Adds a new element to a specific index of the dynamic array
 * @details If the capacity of the array is not enough to add a new element, the array is resized to double its capacity
 *
 * @param index The index at which to add the new element
 * @param value The value of the element to be added
 */
template<typename type>
void DynamicArray<type>::addToPosition(size_t index, type value) {
    if (index < 0 || index >= length)
        throw std::out_of_range("index out of range");

    if (length == capacity)
        automaticResize();

    //Shift all elements beginning from index to the right
    for (size_t i = index; i < length - 1; i++)
        array[i] = array[i + 1];

    array[index] = value;
    length++;
}

/**
 * @brief Deletes the last element of the dynamic array
 * @details Check if the current length of the array is a quarter of the capacity and resize the array to half the
 * current size
 */
template<typename type>
void DynamicArray<type>::deleteFromEnd() {
    length--;

    if (length == capacity / 4)
        resize(capacity / 2);
}

/**
 * @brief Deletes the last element at a specific index of the dynamic array
 * @param index The index of the element to be deleted
 *
 * @details Check if the current length of the array is a quarter of the capacity and resize the array to half the
 * current size
 */
template<typename type>
void DynamicArray<type>::deleteFromPosition(size_t index) {
    if (index < 0 || index >= length)
        throw std::out_of_range("index out of range");

    // Shift all elements beginning from index+1 to the left
    for (size_t i = index; i < length - 1; i++)
        array[i] = array[i + 1];

    length--;

    if (length == capacity / 4)
        resize(capacity / 2);
}