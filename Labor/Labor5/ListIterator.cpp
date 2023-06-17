#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

/**
* @brief Iterator constructor
* @complexityΩ θ(1)
* @complexityθ θ(log n)
* @complexityO θ(n)
**/
ListIterator::ListIterator(const SortedIndexedList &list) : list(list) {
    current = list.head;
    while (current != nullptr && current->left != nullptr) {
        current = current->left; //Minimum element
    }
}

/**
* @brief Set the iterator on the first position
* @complexityΩ θ(1)
* @complexityθ θ(log n)
* @complexityO θ(n)
**/
void ListIterator::first() {
    current = list.head;
    while (current != nullptr && current->left != nullptr) {
        current = current->left; //Minimum element
    }
}

/**
* @brief Get the next element in the list
* @complexity θ(1)
**/
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

/**
* @brief Check if the iterator is valid
* @complexity θ(1)
**/
bool ListIterator::valid() const {
    return current != nullptr;
}

/**
* @brief Get the value of the current element
* @complexity θ(1)
**/
TComp ListIterator::getCurrent() const {
    return current->value;
}