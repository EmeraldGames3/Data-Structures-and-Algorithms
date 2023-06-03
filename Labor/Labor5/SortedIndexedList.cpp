#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
#include <exception>

using namespace std;

SortedIndexedList::SortedIndexedList(Relation r) {
    relation = r; //relation(e, value) == e <= value
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
    if (i < 0 || i >= this->nrElems) {
        throw std::out_of_range("Invalid position in the list!");
    }

    Node *current = this->head;
    int position = 0;

    while (current != nullptr) {
        int leftSize = current->nrLeftElements;

        if (i == (position + leftSize)) {
            return current->value;
        }

        if (i < (position + leftSize)) {
            current = current->left;
        } else {
            position = position + leftSize + 1;
            current = current->right;
        }
    }

    return NULL_TCOMP;
}

TComp SortedIndexedList::remove(int i) {
    if (i < 0 || i > nrElems - 1)
        throw exception();

    Node *current = head;
    int currentPosition = head->nrLeftElements;
    TComp deletedValue;

    while (currentPosition != i) {
        if (i < currentPosition) {
            current = current->left;
            currentPosition--;
            int nrRightTreeElements = current->parent->nrLeftElements - current->nrLeftElements - 1;
            current->parent->nrLeftElements--;
            currentPosition -= nrRightTreeElements;
        } else {
            current = current->right;
            currentPosition++;
            currentPosition += current->nrLeftElements;
        }
    }

    deletedValue = current->value;

    if (current == head) {
        if (head->right == nullptr && head->left == nullptr) {
            delete current;
            head = nullptr;
        } else if (head->right == nullptr && head->left != nullptr) {
            head = head->left;
            delete current;
            head->parent = nullptr;
        } else if (head->right != nullptr && head->left == nullptr) {
            head = head->right;
            delete current;
            head->parent = nullptr;
        } else {

        }
    } else {
        Node *parent = current->parent;
        if (current->right == nullptr && current->left == nullptr) {
            if (parent->left == current)
                parent->left = nullptr;
            else
                parent->right = nullptr;
            delete current;
        } else if (current->right != nullptr && current->left == nullptr) {
            if (parent->left == current)
                parent->left = current->right;
            else
                parent->right = current->right;
            (current->right)->parent = parent;
            delete current;
        } else if (current->right == nullptr && current->left != nullptr) {
            if (parent->left == current)
                parent->left = current->left;
            else
                parent->right = current->left;
            (current->left)->parent = parent;
            delete current;
        } else {

        }
    }

    nrElems--;
    return deletedValue;
}

int SortedIndexedList::search(TComp e) const {
    if (isEmpty())
        return -1;

    Node *current = head;
    int position = head->nrLeftElements;

    while (current != nullptr) {
        if (current->value == e) {
            return position;
        }
        if (relation(e, current->value)) {
            current = current->left;
            if (current != nullptr)
                position -= (current->parent->nrLeftElements - current->nrLeftElements);
        } else {
            current = current->right;
            if (current != nullptr)
                position += (current->nrLeftElements + 1);
        }
    }

    return -1;
}

void SortedIndexedList::add(TComp e) {
    Node *current = head;
    Node *newNode = new Node{e, nullptr, nullptr, nullptr, 0};

    nrElems++;
    if (current == nullptr) {
        head = newNode;
        return;
    }

    if ((!relation(e, head->value) || e == head->value) && head->right == nullptr) {
        head->right = newNode;
        newNode->parent = head;
        return;
    }

    if ((relation(e, head->value) && e != head->value) && head->left == nullptr) {
        head->nrLeftElements = 1;
        head->left = newNode;
        newNode->parent = head;
        return;
    }

    if (relation(e, head->value) && e != head->value) {
        current = head->left;
        head->nrLeftElements++;
    } else {
        current = head->right;
    }

    Node *parent = current;
    while (current != nullptr) {
        parent = current;
        if (relation(e, current->value) && e != current->value) {
            current->nrLeftElements++;
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;
    if (relation(e, parent->value) && newNode->value != parent->value)
        parent->left = newNode;
    else
        parent->right = newNode;
}

ListIterator SortedIndexedList::iterator() {
    return ListIterator(*this);
}

SortedIndexedList::~SortedIndexedList() {
    Node **nodeStack = new Node *[nrElems];
    int top = -1;

    Node *current = head;
    Node *lastVisited = nullptr;

    while (current != nullptr || top != -1) {
        if (current) {
            nodeStack[++top] = current;
            current = current->left;
        } else {
            Node *peekNode = nodeStack[top];

            if (peekNode->right && lastVisited != peekNode->right) {
                current = peekNode->right;
            } else {
                top--;
                lastVisited = peekNode;
                delete peekNode;
            }
        }
    }

    delete[] nodeStack;
}