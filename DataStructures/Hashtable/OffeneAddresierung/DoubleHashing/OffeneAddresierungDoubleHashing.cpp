#include <iostream>
#include "OffeneAddresierungDoubleHashing.h"

OffeneAddressierungDoubleHashing::OffeneAddressierungDoubleHashing() {
    capacity = 100;
    size = 0;
    table = new TKey[capacity];
    hash1 = hashF1;
    hash2 = hashF2;

    for(int i = 0; i < capacity; i++){
        table[i] = NULL_TKEY;
    }
}

OffeneAddressierungDoubleHashing::~OffeneAddressierungDoubleHashing() {
    delete[] table;
}

void OffeneAddressierungDoubleHashing::add(TKey key) {
    if (size >= capacity) {
        // Table is full, cannot add more elements
        return;
    }

    int position = hash1(key, capacity);
    int offset = hash2(key, capacity);
    int step = 1;

    while (table[position] != NULL_TKEY) {
        position = (position + offset * step) % capacity;
        step++;

        // If the entire table has been probed, return without adding the key
        if (step > capacity) {
            return;
        }
    }

    table[position] = key;
    size++;
}

void OffeneAddressierungDoubleHashing::remove(TKey key) {
    int position = hash1(key, capacity);
    int offset = hash2(key, capacity);
    int step = 1;

    while (table[position] != NULL_TKEY) {
        if (table[position] == key) {
            table[position] = NULL_TKEY;
            size--;
            return;
        }

        position = (position + offset * step) % capacity;
        step++;
    }
}

bool OffeneAddressierungDoubleHashing::search(TKey key) {
    int position = hash1(key, capacity);
    int offset = hash2(key, capacity);
    int step = 1;

    while (table[position] != NULL_TKEY) {
        if (table[position] == key) {
            return true;
        }

        position = (position + offset * step) % capacity;
        step++;
    }

    return false;
}

void OffeneAddressierungDoubleHashing::printTable() {
    for (int i = 0; i < capacity; i++) {
        std::cout << "[" << i << "]";

        if (table[i] == NULL_TKEY)
            std::cout << "Empty";
        else
            std::cout << table[i];

        std::cout << std::endl;
    }
}