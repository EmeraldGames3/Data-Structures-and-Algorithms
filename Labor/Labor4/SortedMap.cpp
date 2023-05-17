#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <cmath>
#include <iostream>

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
    automaticResize();

    Node *newNode = new Node{TElem{k, v}};
    int position = hash(k, capacity);

    TValue oldValue = NULL_TVALUE;

    if (table[position] == nullptr) {
        table[position] = newNode;
    } else {
        Node *current = table[position];

        while (current != nullptr) {
            if (current->key == k) {
                oldValue = current->value;
                current->value = v;
                return oldValue;
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
        Node *currentNode = head;

        while (currentNode != nullptr && relation(currentNode->key, k)) {
            currentNode = currentNode->next;
        }

        if (currentNode == head) {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
            head->previous = nullptr;
        } else if (currentNode == nullptr) {
            // we add the element onto the end of the list
            newNode->previous = tail;
            tail->next = newNode;
            tail = newNode;
            tail->next = nullptr;
        } else {
            Node *previousNode = currentNode->previous;

            previousNode->next = newNode;
            newNode->previous = previousNode;
            newNode->next = currentNode;
            currentNode->previous = newNode;
        }
    }

    nrElements++; // Increment nrElements after adding a new node
    return oldValue;
}

TValue SortedMap::search(TKey k) const {
    if (isEmpty())
        return NULL_TVALUE;

    int position = hash(k, capacity);
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
    if (isEmpty()) {
        return NULL_TVALUE;
    }

    int position = hash(k, capacity);

    Node *current = table[position];
    Node *previousNode = nullptr;

    Node *nodeToBeRemoved = nullptr;

    while (current != nullptr && current->key != k) {
        previousNode = current;
        current = current->nextCollision;
    }

    if (current == nullptr) {
        //Node is not in the map
        nrElements--;
        return NULL_TVALUE;
    }

    if (size() == 1) {
        head = nullptr;
        tail = nullptr;
        nrElements = 0;
        TValue value = current->value;
        delete nodeToBeRemoved;
        return value;
    }

    //Remove the node from the collisions list
    nodeToBeRemoved = current;
    previousNode->nextCollision = current->nextCollision;

    if (nodeToBeRemoved == head) {
        if (nodeToBeRemoved == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->previous = nullptr;
        }
        nrElements--;
        TValue value = nodeToBeRemoved->value;
        delete nodeToBeRemoved;
        return value;
    }

    if (nodeToBeRemoved == tail) {
        tail = tail->previous;
        tail->next = nullptr;
        nrElements--;
        TValue value = nodeToBeRemoved->value;
        delete nodeToBeRemoved;
        return value;
    }

    (nodeToBeRemoved->next)->previous = nodeToBeRemoved->previous;
    (nodeToBeRemoved->previous)->next = nodeToBeRemoved->next;

    nrElements--;
    TValue value = nodeToBeRemoved->value;
    delete nodeToBeRemoved;
    return value;
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
    Node *current = head;
    Node *previous;
    while (current != nullptr){
        previous = current;
        current = current->next;
        delete[] previous;
    }

    for(int i = 0; i < capacity; i++){
        table[i] = nullptr;
    }
    delete[] table;

    head = nullptr;
    tail = nullptr;
    nrElements = 0;
}

int SortedMap::hash(TKey key, int n) {
    return abs(key) % n;
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

void SortedMap::findFirstPrime(int number) {
    if (number % 2 == 0) {
        number++;
    }
    while (!isPrime(number)) {
        number += 2;
    }
}

void SortedMap::resize(int newCapacity) {
    Node** newTable = new Node*[newCapacity];

    // Initialize the new table with nullptr
    for (int i = 0; i < newCapacity; i++) {
        newTable[i] = nullptr;
    }

    // Rehash all the existing elements into the new table
    Node* currentNode = head;
    while (currentNode != nullptr) {
        int newPosition = hash(currentNode->key, newCapacity);

        // Insert the node at the beginning of the linked list
        currentNode->nextCollision = newTable[newPosition];
        newTable[newPosition] = currentNode;

        currentNode = currentNode->next;
    }

    // Delete the old table and update with the new one
    delete[] table;
    table = newTable;
    capacity = newCapacity;
}

void SortedMap::automaticResize() {
    if(nrElements == capacity){
        int newCapacity = capacity * 2;
        findFirstPrime(newCapacity);
        resize(newCapacity);
    }
}
