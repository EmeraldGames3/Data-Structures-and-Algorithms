#include <stdexcept>
#include "SortedBag.h"
#include "../SortedBagIterator/SortedBagIterator.h"

/**
 * Class constructor
 * @param r The relationship by which the elements of the array are sorted
 */
SortedBag::SortedBag(Relation r) {
    length = 0;
    capacity = 10;
    dynamicArray = new TElem[capacity];
    relation = r;
}

/**
 * Add an element to the array
 * @param e An element of type TComp
 * @complexity O(n)
 */
void SortedBag::add(TComp e) {
    // Increase the length of the array and resize it if needed
    length++;
    automaticResize();

    // Find the correct position for the new element
    int position = length - 1;
    while (position > 0 && relation(e, dynamicArray[position - 1])) {
        dynamicArray[position] = dynamicArray[position - 1];
        position--;
    }

    // Insert the new element in the correct position
    dynamicArray[position] = e;
}

/**
 * @param e An element of type TComp
 * @return true if e was deleted from the array, false otherwise
 * @complexity O(n)
 */
bool SortedBag::remove(TComp e) {
    int i = 0;

    //Find the position of e
    while (i < length && dynamicArray[i] != e) i++;
    if (i == length) return false;//E is not in the array

    //Shift all elements that come one position after e to the right so that e becomes the last element
    for (int j = i; j < length - 1; j++) dynamicArray[j] = dynamicArray[j + 1];

    //Delete e by decrementing the length of the array
    length--;
    automaticResize(); // Resize the array if needed
    return true;
}

/**
 * @param elem A variable of type TComp
 * @return true if the element is present in the list, false otherwise
 * @complexity O(log n), as we use binary search
 */
bool SortedBag::search(TComp elem) const {
    if (isEmpty()) return false;

    for (int i = 0; i < length; i++)
        if (elem == dynamicArray[i])
            return true;

    return false;
}

/**
 * @param elem A variable of type TComp
 * @return The amount of times the element appears in the array
 * @complexity O(n)
 */
int SortedBag::nrOccurrences(TComp elem) const {
    if (isEmpty()) return 0; // The array is empty

    int counter = 0;
    for (int i = 0; i < length; i++)
        if (elem == dynamicArray[i])
            counter++;

    return counter;
}

/**
 * @return The length of the array
 * @complexity θ(1)
 */
int SortedBag::size() const { return length; }

/**
 * @return true if the array is empty, false otherwise
 * @complexity θ(1)
 */
bool SortedBag::isEmpty() const {
    if (length == 0) return true;
    return false;
}

/**
 * @return An iterator for this sorted bag
 */
SortedBagIterator SortedBag::iterator() const { return SortedBagIterator(*this); }

/**
 * Class destructor
 */
SortedBag::~SortedBag() { delete[] dynamicArray; }

/**
 * @deprecated
 * Sort the array using the bubble-sort algorithm
 * @complexity O(n^2)
 */
void SortedBag::sort() {
    for (int i = 0; i < length - 1; i++)
        for (int j = 0; j < length - 1; j++)
            if (!relation(dynamicArray[j], dynamicArray[j + 1])) {
                TElem temp = dynamicArray[j + 1];
                dynamicArray[j + 1] = dynamicArray[j];
                dynamicArray[j] = temp;
            }
}

/**
 * Resize the array to a new capacity
 * @throws out_of_range if newCapacity < length
 * @complexity θ(n)
 */
void SortedBag::resize(int newCapacity) {
    if (newCapacity < length) throw std::out_of_range("Index out of range");

    auto *newArray = new TElem[newCapacity];
    for (size_t i = 0; i < length; i++) newArray[i] = dynamicArray[i];

    delete[] dynamicArray;
    dynamicArray = newArray;
    capacity = newCapacity;
}

/**
 * Automatically resizes the array
 * @details If capacity == length a new block of memory is allocated for the dynamic array with enough space
 * and the old one is deleted. If the length of the array becomes equal to one quarter of the capacity the array is
 * resized to half its capacity as not to waste too much memory
 * @complexity θ(1)
 */
void SortedBag::automaticResize() {
    if (length == capacity) resize(capacity * 2);
    if (length <= capacity / 4 && capacity >= 10) resize(capacity / 2);
}
