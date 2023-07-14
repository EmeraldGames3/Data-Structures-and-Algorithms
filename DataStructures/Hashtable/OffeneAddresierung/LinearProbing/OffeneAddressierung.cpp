#include <iostream>
#include "OffeneAddressierungLinearProbing.h"
#include "OffeneAddresierungIterator.h"

OffeneAddressierungLinearProbing::OffeneAddressierungLinearProbing() {
    capacity = 100;
    size = 0;
    hashFunction = hashDivisionsMethode;

    table = new TKey[capacity];

    for (int i = 0; i < capacity; i++)
        table[i] = NULL_TKEY;
}

OffeneAddressierungLinearProbing::~OffeneAddressierungLinearProbing() {
    delete[] table;
}

void OffeneAddressierungLinearProbing::add(TKey key) {
    int position = hashFunction(key, capacity);

    // Linear probing until an empty slot is found
    while (table[position] != NULL_TKEY) {
        position = (position + 1) % capacity;
    }

    // Insert the key into the empty slot
    table[position] = key;
    size++;
}

void OffeneAddressierungLinearProbing::remove(TKey key) {
    int position = hashFunction(key, capacity);

    // Linear probing until the key is found or an empty slot is encountered
    while (table[position] != key && table[position] != NULL_TKEY) {
        position = (position + 1) % capacity;
    }

    // If the key is found, mark the slot as empty
    if (table[position] == key) {
        table[position] = NULL_TKEY;
        size--;
    }
}

bool OffeneAddressierungLinearProbing::search(TKey key) {
    int position = hashFunction(key, capacity);

    // Linear probing until the key is found or an empty slot is encountered
    while (table[position] != key && table[position] != NULL_TKEY) {
        position = (position + 1) % capacity;
    }

    // Return true if the key is found, false otherwise
    return (table[position] == key);
}

void OffeneAddressierungLinearProbing::printTable() {
    for (int i = 0; i < capacity; i++) {
        if (table[i] != NULL_TKEY) {
            std::cout << "Position " << i << ": " << table[i] << std::endl;
        }
    }
}

OffeneAddressierungLinearProbingIterator OffeneAddressierungLinearProbing::getIterator() {
    return OffeneAddressierungLinearProbingIterator(*this);
}