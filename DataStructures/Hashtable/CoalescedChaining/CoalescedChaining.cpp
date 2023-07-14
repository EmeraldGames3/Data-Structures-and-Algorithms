#include <iostream>
#include "CoalescedChaining.h"
#include "CoalescedChainingIterator.h"

CoalescedChaining::CoalescedChaining() {
    firstEmpty = 0;
    size = 0;
    capacity = 100;
    table = new TKey[capacity];
    next = new int[capacity];
    hash = hashDivisionsMethode;

    for(int i = 0; i < capacity; i++){
        table[i] = NULL_TKEY;
        next[i] = -1;
    }
}

void CoalescedChaining::changeFirstEmpty() {
    while (table[firstEmpty] != NULL_TKEY && firstEmpty < capacity){
        firstEmpty++;
    }
}

CoalescedChaining::~CoalescedChaining() {
    delete[] table;
    delete[] next;
}

CoalescedChainingIterator CoalescedChaining::getIterator() {
    return CoalescedChainingIterator(*this);
}

void CoalescedChaining::add(TKey key) {
    int position = hash(key, capacity);

    // If the slot is empty, insert the key directly
    if (table[position] == NULL_TKEY) {
        table[position] = key;
        next[position] = -1;

    } else {
        // Find an empty slot to insert the key
        int current = position;
        while (next[current] != -1) {
            current = next[current];
        }

        int newEmpty = firstEmpty;
        firstEmpty = next[firstEmpty];

        table[newEmpty] = key;
        next[newEmpty] = -1;
        next[current] = newEmpty;
    }

    if (table[firstEmpty] != NULL_TKEY)
        changeFirstEmpty();
}

void CoalescedChaining::remove(TKey key) {

    int position = hash(key, capacity);
    int current = position;
    int previous = -1;

    while(current != -1 && table[current] != key) {
        previous = current;
        current = next[current];
    }

    if(current != -1) {

        if(previous == -1) {
            table[position] = NULL_TKEY;
            next[position] = -1;
        }
        else {
            next[previous] = next[current];
        }

        table[current] = NULL_TKEY;
        next[current] = -1;
    }
}

bool CoalescedChaining::search(TKey key) {

    int position = hash(key, capacity);
    int current = position;

    while(current != 1 && table[current] != key) {
        current = next[current];
    }

    return (current != -1);
}

void CoalescedChaining::printTable() {
    for(int i = 0; i < capacity; i++) {
        std::cout << "[" << i << "]:";

        if(table[i] == NULL_TKEY)
            std::cout << "Empty";
        else
            std::cout << table[i];

        std::cout << " -> ";

        int nextIndex = next[i];
        while(nextIndex != -1) {
            std::cout << table[nextIndex] << " -> ";
            nextIndex = next[nextIndex];
        }

        std::cout << "NULL" << std::endl;
    }
}