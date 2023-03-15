#include <stdexcept>
#include "SortedBag.h"
#include "../SortedBagIterator/SortedBagIterator.h"

/**
 * Class constructor
 * @param r The relationship by which the elements of the array are sorted
 * @complexity θ(1), for every case this function executes a constant amount of steps
 */
SortedBag::SortedBag(Relation r) {
    this->length = 0;
    this->capacity = 10;
    this->dynamicArray = new TElem[capacity];
    this->relation = r;
}

/**
 * Add an element to the array
 * @param e An element of type TComp
 * @complexity θ(n) for every case this function executes n steps
 */
void SortedBag::add(TComp e) {
    // Increase the length of the array and resize it if needed
    this->length++;
    automaticResize();

    // Find the correct position for the new element
    int position = this->length - 1;
    while (position > 0 && this->relation(e, this->dynamicArray[position - 1])) {
        this->dynamicArray[position] = this->dynamicArray[position - 1];
        position--;
    }

    // Insert the new element in the correct position
    this->dynamicArray[position] = e;
}

/**
 * @param e An element of type TComp
 * @return true if e was deleted from the array, false otherwise
 * @complexity O(n)
 */
bool SortedBag::remove(TComp e) {
    int i = 0;

    //Find the position of e
    while (i < this->length && this->dynamicArray[i] != e)
        i++;
    if (i == this->length) return false;//E is not in the array

    //Shift all elements that come one position after e to the right so that e becomes the last element
    for (int j = i; j < this->length - 1; j++)
        this->dynamicArray[j] = this->dynamicArray[j + 1];

    //Delete e by decrementing the length of the array
    this->length--;
    automaticResize(); // Resize the array if needed
    return true;
}

/**
 * @param elem A variable of type TComp
 * @return true if the element is present in the list, false otherwise
 * @complexityΩ θ(1)
 * @complexityθ θ(log n)
 * @complexityO θ(log n)
 */
bool SortedBag::search(TComp elem) const {
    if (isEmpty()) return false;
    if (binarySearch(elem) < 0) return false;
    return true;
}

/**
 * @param elem A variable of type TComp
 * @return The amount of times the element appears in the array
 * @complexityΩ θ(1)
 * @complexityθ θ(log n)
 * @complexityO θ(n)
 */
int SortedBag::nrOccurrences(TComp elem) const {
    if (isEmpty()) return 0; // The array is empty

    //perform a binary search
    int indexElement = binarySearch(elem);
    if (indexElement < 0) return 0; // The element is not in the array

    int counter = 1;
    // search to the right of the found position
    int i = indexElement + 1;
    while (elem == this->dynamicArray[i] && i < this->length) {
        counter++;
        i++;
    }
    //search to the left of the found position
    i = indexElement - 1;
    while (elem == this->dynamicArray[i] && i >= 0) {
        counter++;
        i--;
    }
    return counter;
}

/**
 * @return The length of the array
 * @complexity θ(1), for every case this function executes a constant amount of steps
 */
int SortedBag::size() const { return this->length; }

/**
 * @return true if the array is empty, false otherwise
 * @complexity θ(1), for every case this function executes a constant amount of steps
 */
bool SortedBag::isEmpty() const {
    if (this->length <= 0) return true;
    return false;
}

/**
 * @return An iterator for this sorted bag
 * @complexity θ(1)
 */
SortedBagIterator SortedBag::iterator() const { return SortedBagIterator(*this); }

/**
 * Class destructor
 * @complexity θ(n), for every case this function executes exactly n steps
 */
SortedBag::~SortedBag() { delete[] this->dynamicArray; }

/**
 * @deprecated This function is legacy code and should not be used
 * Sort the array using the bubble-sort algorithm
 * @complexityΩ θ(n)
 * @complexityθ θ(n^2)
 * @complexityO θ(n^2)
 */
void SortedBag::sort() {
    for (int i = 0; i < this->length - 1; i++)
        for (int j = 0; j < this->length - 1; j++)
            if (!this->relation(this->dynamicArray[j], this->dynamicArray[j + 1])) {
                TElem temp = this->dynamicArray[j + 1];
                this->dynamicArray[j + 1] = this->dynamicArray[j];
                this->dynamicArray[j] = temp;
            }
}

/**
 * Resize the array to a new capacity
 * @throws out_of_range if newCapacity < length
 * @complexity θ(n), for every case this function performs exactly n steps
 */
void SortedBag::resize(int newCapacity) {
    if (newCapacity < this->length) throw std::out_of_range("Index out of range");

    auto *newArray = new TElem[newCapacity];
    for (size_t i = 0; i < this->length; i++)
        newArray[i] = this->dynamicArray[i];

    delete[] this->dynamicArray;
    this->dynamicArray = newArray;
    this->capacity = newCapacity;
}

/**
 * Automatically resizes the array
 * @details If capacity == length a new block of memory is allocated for the dynamic array with enough space
 * and the old one is deleted. If the length of the array becomes equal to one quarter of the capacity the array is
 * resized to half its capacity as not to waste too much memory
 * @complexityΩ θ(1)
 * @complexityθ θ(1) (costuri amortizate)
 * @complexityO θ(n)
 */
void SortedBag::automaticResize() {
    if (this->length == this->capacity) resize(this->capacity * 2);
    if (this->length <= this->capacity / 4 && this->capacity >= 10) resize(this->capacity / 2);
}

/**
 *  Perform a binary search on the array to fin an elemeny
 * @param element The element we search
 * @return The position of the element or -1 if the element is not found in the array
 * @complexityΩ θ(1)
 * @complexityθ θ(log n)
 * @complexityO θ(log n)
 */
int SortedBag::binarySearch(int element) const {
    int left = 0;
    int right = this->length - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (this->dynamicArray[mid] == element) {
            return mid; // Found target, return index
        } else if (this->relation(this->dynamicArray[mid], element)) {
            left = mid + 1; // Target is in right half
        } else {
            right = mid - 1; // Target is in left half
        }
    }

    return -1; // Target not found in array
}
