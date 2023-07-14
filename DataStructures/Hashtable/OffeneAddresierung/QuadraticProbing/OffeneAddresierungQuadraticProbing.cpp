#include <iostream>
#include "OffeneAddresierungQuadraticProbing.h"
#include "OffeneAddresierungQuadraticProbingIterator.h"

OffeneAddressierungQuadraticProbing::OffeneAddressierungQuadraticProbing() {
    capacity = 100;
    size = 0;
    table = new TKey[capacity];
    hash = hashDivisionsMethode;

    for(int i = 0; i < capacity; i++) {
        table[i] = NULL_TKEY;
    }
}

OffeneAddressierungQuadraticProbing::~OffeneAddressierungQuadraticProbing() {
    delete[] table;
}

void OffeneAddressierungQuadraticProbing::add(TKey key) {

    int position = hash(key, capacity);

    int step = 1;

    while(table[position] != NULL_TKEY) {
        position = (position + step * step) % capacity;
        step++;

        if(position < 0)
            position += capacity;
    }

    table[position] = key;
    size++;
}

void OffeneAddressierungQuadraticProbing::remove(TKey key) {
    int position = hash(key, capacity);
    int step = 1;

    while(table[position] != key && table[position] != NULL_TKEY) {
        position = (position + step * step) % capacity;
        step++;

        if(position < 0)
            position += capacity;

        if(step > capacity) {
            return;
        }
    }

    if(table[position] == key) {
        table[position] = NULL_TKEY;
        size--;
    }
}

bool OffeneAddressierungQuadraticProbing::search(TKey key) {
    int position = hash(key, capacity);
    int step = 1;

    while(table[position] != key && table[position] != NULL_TKEY) {
        position = (position + step * step) % capacity;
        step++;

        if(position < 0)
            position += capacity;

        if(step > capacity) {
            return false;
        }
    }

    return(table[position] == key);
}

void OffeneAddressierungQuadraticProbing::printTable() {
    for (int i = 0; i < capacity; i++) {
        std::cout << "[" << i << "]";

        if (table[i] == NULL_TKEY)
            std::cout << "Empty";
        else
            std::cout << table[i];

        std::cout << std::endl;
    }
}

OffeneAddressierungQuadraticProbingIterator OffeneAddressierungQuadraticProbing::getIterator() {
    return OffeneAddressierungQuadraticProbingIterator(*this);
}