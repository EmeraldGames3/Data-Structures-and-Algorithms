#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList &list) : list(list) {
    current = list.head;
    while (current != nullptr && current->left != nullptr) {
        current = current->left; //Minimum element
    }
}

void ListIterator::first() {
    current = list.head;
    while (current != nullptr && current->left != nullptr) {
        current = current->left; //Minimum element
    }
}

void ListIterator::next() {
    if (!valid())
        throw exception();

    if (current->right != nullptr) {
        current = current->right;
        while (current->left != nullptr) {
            current = current->left;
        }
    } else {
        Node *parent = current->parent;
        while (parent != nullptr && parent->left != current) {
            current = parent;
            parent = current->parent;
        }
        current = parent;
    }
}

bool ListIterator::valid() const {
    return current != nullptr;
}

TComp ListIterator::getCurrent() const {
    return current->value;
}