#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

#include <exception>
#include <stack>

SortedIndexedList::SortedIndexedList(Relation r) {
    relation = r;
    nrElems = 0;
    head = nullptr;
}

int SortedIndexedList::size() const {
    return nrElems;
}

bool SortedIndexedList::isEmpty() const {
    return nrElems == 0;
}

TComp SortedIndexedList::getElement(int i) const {
    if (isEmpty())
        throw exception();

    if (i > nrElems - 1) {
        throw exception();
    }

    if (i < 0) {
        throw exception();
    }

    return NULL_TCOMP;
}

TComp SortedIndexedList::remove(int i) {
    if (isEmpty())
        throw exception();

    if (i > nrElems - 1) {
        throw exception();
    }

    if (i < 0) {
        throw exception();
    }

    Node *deletedNode;
    TComp deletedValue;

    if (head->left == nullptr && head->right == nullptr) {
        deletedValue = head->value;
        deletedNode = head;
    }

    nrElems--;
    delete deletedNode;
    return deletedValue;
}

int SortedIndexedList::search(TComp e) const {
    if (isEmpty())
        return -1;

    if (head->value == e) {
        return head->nrLeftElements;
    }

    int currentPosition = head->nrLeftElements;
    Node *current = head;

    while (current->left != nullptr || current->right != nullptr) {
        if (current->value == e) {
            return currentPosition;
        } else if (relation(e, current->value)) {
            //current->value >= e
            //Search in the left tree
            if (current->left == nullptr) {
                //Element is not in the list
                return -1;
            }

            int lastNrLeftElements = current->nrLeftElements;
            current = current->left;
            currentPosition -= ((lastNrLeftElements - currentPosition) + 1);
        } else {
            //Search in the right tree
            if (current->right == nullptr) {
                //Element is not in the list
                return -1;
            }

            current = current->right;
            currentPosition += (current->nrLeftElements + 1);
        }
    }

    return -1;
}

void SortedIndexedList::add(TComp e) {
    Node *current = head;
    Node *newNode = new Node{e, nullptr, nullptr, nullptr, 0};

    if (current == nullptr) {
        head = newNode;
        nrElems = 1;
        return;
    }

    while (current->left != nullptr || current->right != nullptr) {
        if (relation(e, current->value)) {
            //current->value >= e
            //The value is located in the left tree
            current->nrLeftElements += 1;

            if (current->left == nullptr) {
                newNode->parent = current;
                current->left = newNode;
                nrElems++;
                return;
            }

            current = current->left;
        } else {
            //The value is located in the right tree

            if (current->right == nullptr) {
                newNode->parent = current;
                current->right = newNode;
                nrElems++;
                return;
            }

            current = current->right;
        }
    }

    if (relation(e, current->value)){
        newNode->parent = current;
        current->left = newNode;
        nrElems++;
        return;
    } else{
        newNode->parent = current;
        current->right = newNode;
        nrElems++;
        return;
    }
}

ListIterator SortedIndexedList::iterator() {
    return ListIterator(*this);
}

SortedIndexedList::~SortedIndexedList(){

}