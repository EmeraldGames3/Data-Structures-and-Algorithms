#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>

using namespace std;

SortedBag::SortedBag(Relation r) {
    //TODO - Implementation
    relation = r;
    capacity = 20;
    nodes = new dllaNode[capacity];
    sizeArray = 0;
    head = -1;
    tail = -1;
    firstEmpty = 0;
    for (int i = 0; i < capacity; i++) {
        nodes[i].previous = i - 1;
        nodes[i].next = i + 1;
    }
    nodes[0].previous = -1;
    nodes[capacity - 1].next = -1;


}

int SortedBag::allocate() {
    int position = firstEmpty;
    if (position != -1) {
        firstEmpty = nodes[firstEmpty].next;
        if (firstEmpty != -1)
            nodes[firstEmpty].previous = -1;
        nodes[position].next = -1;
        nodes[position].previous = -1;
    }
    return position;
}

void SortedBag::free(int position) {
    nodes[position].next = firstEmpty;
    nodes[position].previous = -1;
    if (firstEmpty != -1)
        nodes[firstEmpty].previous = position;
    firstEmpty = position;
}

void SortedBag::resizeUp() {
    int newCapacity = 2 * capacity;
    dllaNode *newNodes = new dllaNode[newCapacity];
    for (int i = 0; i < capacity; i++)
        newNodes[i] = nodes[i];
    for (int i = 0; i < newCapacity; i++) {
        newNodes[i].previous = i - 1;
        newNodes[i].next = i + 1;
    }
    delete[] nodes;
    this->capacity = newCapacity;
    this->nodes = newNodes;
}

void SortedBag::resizeDown() {
    int newCapacity = capacity + 5;
    dllaNode *newNodes = new dllaNode[newCapacity];
    for (int i = 0; i < capacity; i++)
        newNodes[i] = nodes[i];
    for (int i = 0; i < newCapacity; i++) {
        newNodes[i].previous = i - 1;
        newNodes[i].next = i + 1;
    }
    delete[] nodes;
    this->capacity = newCapacity;
    this->nodes = newNodes;
}

int SortedBag::findPosition(TComp elem) {
    int left = 0, right = sizeArray - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (relation(nodes[mid].info, elem)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int SortedBag::binarySearch(TComp element, int left, int right) const {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nodes[mid].info == element) {
            return mid;
        }
        if (relation(element, nodes[mid].info)) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

void SortedBag::add(TComp e) {
    if (sizeArray == capacity)
        resizeUp();
    int current = head;
    int prev = -1;
    while (current != -1 && relation(nodes[current].info, e)) {
        prev = current;
        current = nodes[current].next;
    }
    int new_node = allocate();
    nodes[new_node].info = e;
    nodes[new_node].next = current;
    nodes[new_node].previous = prev;
    if (prev != -1) {
        nodes[prev].next = new_node;
    } else {
        head = new_node;
    }
    if (current != -1) {
        nodes[current].previous = new_node;
    } else {
        tail = new_node;
    }
    sizeArray++;

}


bool SortedBag::remove(TComp e) {
    if (isEmpty())
        return false;
    if (sizeArray == capacity / 4)
        resizeDown();
    int current = head;
    bool found = false;
    while (current != -1 && !found) {
        if (nodes[current].info == e)
            found = true;
        current = nodes[current].next;
    }
    if (!found) {
        return false; // element not found
    }
    int nextNode = current;
    current = nodes[current].previous;
    int prevNode = nodes[current].previous;


    // update the previous node's next pointer
    if (prevNode == -1) {
        head = nextNode;
    } else {
        nodes[prevNode].next = nextNode;
    }

    // update the next node's previous pointer
    if (nextNode == -1) {
        tail = prevNode;
    } else {
        nodes[nextNode].previous = prevNode;
    }

    // add the removed node to the free list
    nodes[current].next = firstEmpty;
    nodes[current].previous = -1;
    firstEmpty = current;
    sizeArray--;

    return true;

}


bool SortedBag::search(TComp elem) const {
    if (isEmpty())
        return false;
    for (int i = 0; i < sizeArray; i++)
        if (nodes[i].info == elem)
            return true;
    return false;
}


int SortedBag::nrOccurrences(TComp elem) const {
    if (!search(elem))
        return 0;
    int occurrences = 0;
    for (int i = 0; i < sizeArray; i++)
        if (nodes[i].info == elem)
            occurrences++;
    return occurrences;
}


int SortedBag::size() const {
    return sizeArray;
}


bool SortedBag::isEmpty() const {
    if (sizeArray == 0)
        return true;
    return false;
}


SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
    delete[] nodes;
}
