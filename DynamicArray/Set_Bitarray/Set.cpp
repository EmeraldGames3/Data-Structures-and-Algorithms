#include "Set.h"
#include "SetITerator.h"

/// Complexity: tetha(1)
Set::Set() {
    this->bitArray = nullptr;
    this->capacity = 0;
    this->nrElems = 0;
    this->minimumElement = 0;
}

/// Complexity: O(capacity)
Set::Set(const Set& other) {
    // non static values are copied
    this->capacity = other.capacity;
    this->nrElems = other.nrElems;
    this->minimumElement = other.minimumElement;
    // the values of the bitarray are copied if the bitarray != 0
    if (other.bitArray != nullptr) {
        this->bitArray = new bool[this->capacity];
        for (int i = 0; i < this->capacity; i++) {
            this->bitArray[i] = other.bitArray[i];
        }
    }
    else this->bitArray = nullptr;
}

// preConditions: - both sets are initialised
//                - both sets have unique elements

//postConditions: - the result is a Set type object
//                - the original sets are ot modified
//                - the elements in the result Set are unique

/// Complexity: O(size of the smaller set)
Set Set::intersection(const Set& other) const {
    Set result;

    // iterate over the smaller set and check if each element is present in the other set
    const Set* smallerSet;
    const Set* largerSet;

    if(this->size() < other.size()) {
        smallerSet = this;
        largerSet = &other;
    }
    else {
        smallerSet = &other;
        largerSet = this;
    }

    for (SetIterator it = smallerSet->iterator(); it.valid(); it.next()) {
        TElem current = it.getCurrent();
        if (largerSet->search(current)) {
            result.add(current);
        }
    }
    return result;
}

/// Complexity: tetha(1) if the element fits the array
/// tetha(newArraySize) otherwise
/// amortized complexity is tetha(1)
bool Set::add(TElem elem) {
    // if the array does not exist, we create it
    if (capacity < 1) {
        capacity = 1;
        nrElems = 1;
        minimumElement = elem;
        bitArray = new bool[capacity];
        bitArray[0] = true;
        return true;
    }
    // case 1: the element we want to add fits the current array
    if (elem >= minimumElement && elem < minimumElement + capacity) {
        // check if the element is already in array
        if (bitArray[elem - minimumElement])
            return false;
        else
            bitArray[elem - minimumElement] = true;
    }
    // case 2: the element we want to add is smaller than the minimum element
    else if (elem < minimumElement) {
        //shiftingSize - how many spaces to the right will the old array be translated
        int shiftingSize = minimumElement - elem;
        //the new size for the array
        int newArraySize = capacity + shiftingSize;
        //allocate space for a new array
        bool *auxiliaryArray = new bool[newArraySize];
        //add the element
        auxiliaryArray[0] = true;

        // clear the elements before the previous minimum and the current minimum
        for (int i = 1; i < shiftingSize; i++)
            auxiliaryArray[i] = false;
        // copy the old array's elements onto the new one, shifted shiftingSize positions to the right
        for (int i = 0; i < capacity; i++)
            auxiliaryArray[i + shiftingSize] = bitArray[i];
        // delete the old array
        delete[] bitArray;

        // update the parameters of the array
        bitArray = auxiliaryArray;
        capacity = newArraySize;
        minimumElement = elem;
    }
        // case 3: the element we want to add does not fit the current array but is not smaller than the minimum element (no need to do shifting)
    else {
        // compute the size needed to store the new maximum value
        int maximumElement = minimumElement + capacity - 1;
        int newArraySize = capacity + (elem - maximumElement);
        bool *auxiliaryArray = new bool[newArraySize];

        // copy the old array
        for (int i = 0; i < capacity; i++)
            auxiliaryArray[i] = bitArray[i];
        for (int i = capacity; i < newArraySize - 1; i++)
            auxiliaryArray[i] = false;
        // add elem
        auxiliaryArray[newArraySize - 1] = true;
        //delete the old array
        delete[] bitArray;

        // update the pointer to the array and the size
        bitArray = auxiliaryArray;
        capacity = newArraySize;
    }

    // increase the actual size of the array
    nrElems++;
    return true;
}

/// complexity: tetha(1) if the array can not be represented on an array half the size after removing the element or the element does not exist
/// tetha(arraySize / 2) otherwise, and the dimension of the array halves
bool Set::remove(TElem elem) {
    if (!search(elem))
        return false;

    //delete the element from the array and update the actual size
    bitArray[elem - minimumElement] = false;
    nrElems--;

    // case 1: the element removed was the minimum element
    if (elem == minimumElement) {
        //the new index of the first element (first true value from the array)
        int indexFirstElement = 0;
        while (indexFirstElement < capacity && !bitArray[indexFirstElement])
            indexFirstElement++;

        //if the first half of the array is empty, we resize it, reducing its size to half
        if (indexFirstElement >= capacity / 2) {
            bool *auxiliaryArray;
            int newMinimumElement = minimumElement + indexFirstElement;
            int newArraySize = capacity - indexFirstElement;
            auxiliaryArray = new bool[newArraySize];

            //copy the old array into the new one
            for (int i = indexFirstElement; i < capacity; i++)
                auxiliaryArray[i - indexFirstElement] = bitArray[i];
            //delete the new array
            delete[] bitArray;

            //update the parameters of the array
            bitArray = auxiliaryArray;
            capacity = newArraySize;
            minimumElement = newMinimumElement;
        }
    }
    // case 2: the element we removed was the biggest element from the array
    else if (elem == minimumElement + capacity - 1) {
        // find the index of the last value of 1 from the array
        int indexLastElement = capacity - 1;
        while (indexLastElement > 0 && !bitArray[indexLastElement])
            indexLastElement--;

        // if we can represent the array on an array half the size, we resize it.
        if (indexLastElement <= capacity / 2) {
            bool *auxiliaryArray;
            int newArraySize = indexLastElement + 1;
            auxiliaryArray = new bool[newArraySize];
            // copy the old array into the new one
            for (int i = 0; i < newArraySize; i++)
                auxiliaryArray[i] = bitArray[i];
            //delete the old array
            delete[] bitArray;

            //update the parameters of the array
            bitArray = auxiliaryArray;
            capacity = newArraySize;
        }
    }
    return true;
}

/// complexity: tetha(1)
bool Set::search(TElem elem) const {
    // if elem is out of bounds ( < minimum or > maximum) return false
    if (elem < minimumElement || elem >= minimumElement + capacity)
        return false;
    // return the value from the array, which represents whether the element is in the set or not
    return bitArray[elem - minimumElement];
}

/// complexity: tetha(1)
int Set::size() const {
    return nrElems;
}

/// complexity: tetha(1)
bool Set::isEmpty() const {
    return (nrElems == 0);
}

/// complexity: tetha(1)
Set::~Set() {
    delete[] bitArray;
}


SetIterator Set::iterator() const {
    return SetIterator(*this);
}