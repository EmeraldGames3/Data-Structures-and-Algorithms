#include "UnabhangigeVekettung.h"
#include "UnabhangigeVerkettungIterator.h"

UnabhangigeVerkettung::UnabhangigeVerkettung(HashFunction h) {
    capacity = 10000;
    size = 0;
    table = new Node *[capacity];

    for (int i = 0; i < capacity; i++) {
        table[i] = nullptr;
    }

    hash = h;
}

UnabhangigeVerkettung::~UnabhangigeVerkettung() {
    for (int i = 0; i < capacity; i++) {
        if (table[i] != nullptr) {
            delete[] table[i];
        }
    }
    delete[] table;
}

void UnabhangigeVerkettung::resizeAndRehash(int newCapacity) {
    auto **newTable = new Node *[newCapacity];

    for (int i = 0; i < capacity; i++) {
        if (table[i] != nullptr) {
            auto *current = table[i];
            while (current != nullptr) {
                int newPosition = hash(current->element.first, newCapacity);

                Node *newNode = new Node{current->element, newTable[newPosition]};
                newTable[newPosition] = newNode;

                current = current->next;
            }
        }
    }

    for (int i = 0; i < capacity; i++) {
        if (table[i] != nullptr) {
            delete[] table[i];
        }
    }
    delete[] table;

    table = newTable;
    capacity = newCapacity;
}

void UnabhangigeVerkettung::automaticResizeAndRehash() {
//    if (size < capacity / 4 && capacity > 10)
//        resizeAndRehash(capacity / 2);
//    if(size >= capacity)
//        resizeAndRehash(capacity * 2);
}

void UnabhangigeVerkettung::printTable() {
    for (int i = 0; i < capacity; i++) {
        if (table[i] != nullptr) {
            auto *current = table[i];
            while (current != nullptr) {
                std::cout << current->element.first << ' ' << current->element.second << '\n';
                current = current->next;
            }
        }
    }
}

bool UnabhangigeVerkettung::search(TKey key) {
    return table[hash(key, capacity)] != nullptr;
}

void UnabhangigeVerkettung::add(TKey key, TValue value) {
    automaticResizeAndRehash();
    int position = hash(key, capacity);
    Node *newNode = new Node{std::make_pair(key, value), table[position]};
    table[position] = newNode;
    size++;
}

TValue UnabhangigeVerkettung::remove(TKey key, TValue value) {
    int position = hash(key, capacity);

    if (table[position] == nullptr) {
        return NULL_TVALUE;
    } else {
        auto *current = table[position];
        auto *previous = current;
        while (current != nullptr) {
            if (current->element == std::make_pair(key, value)) {
                TValue oldValue = current->element.second;
                size--;
                previous->next = current->next;
                return oldValue;
            }
            previous = current;
            current = current->next;
        }
    }

    return NULL_TVALUE;
}

UnabhangigeVerkettungIterator UnabhangigeVerkettung::getIterator() {
    return UnabhangigeVerkettungIterator(*this);
}
