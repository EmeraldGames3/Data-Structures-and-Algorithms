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
 * @complexity O(n) as it correspondences to the complexity of the sort function
 */
void SortedBag::add(TComp e) {
    length++;
    automaticResize();//Resize the array if needed

    //Add the element to the end of the array and sort the array again
    dynamicArray[length - 1] = e;
    sort();
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

    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        if (dynamicArray[middle] == elem) return true;
        if (relation(dynamicArray[middle], elem)) left = middle + 1;
        else right = middle - 1;
    }

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
    for (int i = 0; i < length; i++) if (elem == dynamicArray[i]) counter++;

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

SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);
}

/**
 * Class destructor
 */
SortedBag::~SortedBag() { delete[] dynamicArray; }

/**
 * Sort the array using the insertion-sort algorithm
 * @complexity θ(n), i am not 100% sure how this is linear but, i found it on the internet
 */
void SortedBag::sort() {
    for (int i = 1; i < length; i++) {
        TElem key = dynamicArray[i];
        int j = i - 1;
        while (j >= 0 && relation(dynamicArray[j], key)) {
            dynamicArray[j + 1] = dynamicArray[j];
            j--;
        }
        dynamicArray[j + 1] = key;
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
