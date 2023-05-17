#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SortedMap::SortedMap(Relation r) {
    relation = r;
    capacity = 13;
    table = new Node *[capacity];
    nrElements = 0;

    for (int i = 0; i < 13; i++) {
        table[i] = nullptr;
    }

    head = nullptr;
    tail = nullptr;
}

TValue SortedMap::add(TKey k, TValue v) {
    Node *newNode = new Node{TElem{k, v}};
    int position = hash(k);
    TValue oldValue = NULL_TVALUE;

    if (table[position] == nullptr) {
        table[position] = newNode;
        nrElements++;
    } else {
        Node *current = table[position];

        while (current != nullptr) {
            if (current->key == k) {
                oldValue = current->value;
                current->value = v;
            }

            current = current->nextCollision;
        }

        newNode->nextCollision = table[position];
        table[position] = newNode;
    }


    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        //TODO: use the relation
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
    }

    return oldValue;
}

TValue SortedMap::search(TKey k) const {
    int position = hash(k);
    Node *current = table[position];

    while (current != nullptr) {
        if (current->key == k) {
            return current->value;
        }

        current = current->nextCollision;
    }

    return NULL_TVALUE;
}

TValue SortedMap::remove(TKey k) {
    //TODO - Implementation
    return NULL_TVALUE;
}

int SortedMap::size() const {
    return nrElements;
}

bool SortedMap::isEmpty() const {
    return nrElements == 0;
}

SMIterator SortedMap::iterator() const {
    return SMIterator(*this);
}

SortedMap::~SortedMap() {
    for (int i = 0; i < capacity; i++) {
        Node *current = table[i];
        while (current != nullptr) {
            auto *oldNode = current;
            current = current->nextCollision;
            delete[] oldNode;
        }
    }

    delete[] table;
}

int SortedMap::hash(TKey key) const {
    return key % capacity;
}

bool SortedMap::isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    if (number <= 3) {
        return true;
    }

    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }

    int i = 5;
    int increment = 2;

    while (i * i <= number) {
        if (number % i == 0) {
            return false;
        }

        i += increment;
        increment = 6 - increment;
    }

    return true;
}

void SortedMap::findFirstPrime() {
    while (!isPrime(capacity)) {
        capacity++;
    }
}