#include "UnabhangigeVerkettungIterator.h"

UnabhangigeVerkettungIterator::UnabhangigeVerkettungIterator(const UnabhangigeVerkettung& t) : hashTable(t) {
    currentPosition = 0;
    while (currentPosition < hashTable.capacity && hashTable.table[currentPosition] == nullptr) {
        currentPosition++;
    }
    if (currentPosition < hashTable.capacity) {
        current = hashTable.table[currentPosition];
    } else {
        current = nullptr; // No non-null node found
    }
}

void UnabhangigeVerkettungIterator::first() {
    currentPosition = 0;
    while (currentPosition < hashTable.capacity && hashTable.table[currentPosition] == nullptr) {
        currentPosition++;
    }
    if (currentPosition < hashTable.capacity) {
        current = hashTable.table[currentPosition];
    } else {
        current = nullptr; // No non-null node found
    }
}

void UnabhangigeVerkettungIterator::next() {
    if (current == nullptr) {
        return; // Already at the end
    }

    if (current->next != nullptr) {
        current = current->next;
    } else {
        currentPosition++; // Move to next position
        while (currentPosition < hashTable.capacity && hashTable.table[currentPosition] == nullptr) {
            currentPosition++;
        }
        if (currentPosition < hashTable.capacity) {
            current = hashTable.table[currentPosition];
        } else {
            current = nullptr; // No non-null node found
        }
    }
}

bool UnabhangigeVerkettungIterator::valid() {
    return currentPosition < hashTable.capacity && current != nullptr;
}

TElem UnabhangigeVerkettungIterator::getCurrent() {
    if (valid())
        return current->element;
    else
        throw std::exception();
}