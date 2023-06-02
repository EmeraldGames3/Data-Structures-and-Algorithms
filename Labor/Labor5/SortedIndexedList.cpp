#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

#include <exception>
#include <stack>

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

    Node* current = this->head;
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
    if (i > nrElems - 1 || i < 0) {
        throw exception();
    }

    Node *nodeToBeDeleted;
    TComp deletedValue;
    int currentPosition = head->nrLeftElements;

    if (head->left == nullptr && head->right == nullptr) {
        deletedValue = head->value;
        nodeToBeDeleted = head;
        nrElems = 0;
        delete nodeToBeDeleted;
        head = nullptr;
        return deletedValue;
    }

    if (i == 0 && head->left == nullptr) {
        //Delete head case 1
        nodeToBeDeleted = head;
        head = head->right;
        nrElems--;
        deletedValue = nodeToBeDeleted->value;
        delete nodeToBeDeleted;
        return deletedValue;
    }

    if (i == nrElems - 1 && head->right == nullptr) {
        //Delete head case 2
        nodeToBeDeleted = head;
        head = head->left;
        nrElems--;
        deletedValue = nodeToBeDeleted->value;
        delete nodeToBeDeleted;
        return deletedValue;
    }

    if (i == head->nrLeftElements) {
        // Delete head case 3
        // Replace head with the minimum in the right subtree and delete the old head
        Node *current = head->right;

        // Find the minimum node in the right subtree
        while (current->left != nullptr) {
            current->nrLeftElements--;
            current = current->left;
        }

        // Replace the value of the head node with the minimum value
        head->value = current->value;

        // Update the parent's link
        Node *parent = current->parent;
        parent->left = current->right;

        // Delete the node
        TComp value = current->value;
        delete current;
        nrElems--;
        return value;
    }

    Node *current;
    Node *parent = head;
    if (i < head->nrLeftElements) {
        //Node is in the left tree
        current = head->left;
        head->nrLeftElements--;
        currentPosition -= (current->parent->nrLeftElements - current->nrLeftElements);
    } else {
        //Node is in the right tree
        current = head->right;
        currentPosition += (current->nrLeftElements + 1);
    }

    // Find the node to be deleted
    while (current != nullptr) {
        parent = current;
        if (currentPosition == i) {
            break;
        }
        if (i < currentPosition) {
            current->nrLeftElements--;
            current = current->left;
            if (current != nullptr)
                currentPosition -= (current->parent->nrLeftElements - current->nrLeftElements);
        } else {
            current = current->right;
            if (current != nullptr)
                currentPosition += (current->nrLeftElements + 1);
        }
    }

    nodeToBeDeleted = parent;
    parent = nodeToBeDeleted->parent;
    deletedValue = nodeToBeDeleted->value;

    //Case 1
    if (nodeToBeDeleted->left == nullptr && nodeToBeDeleted->right == nullptr) {
        if (nodeToBeDeleted == parent->left)
            parent->left = nullptr;
        else
            parent->right = nullptr;
    }

    //Case 2
    if (nodeToBeDeleted->left == nullptr && nodeToBeDeleted->right != nullptr) {
        if (nodeToBeDeleted == parent->left)
            parent->left = nodeToBeDeleted->right;
        else
            parent->right = nodeToBeDeleted->right;
    }
    if (nodeToBeDeleted->right == nullptr && nodeToBeDeleted->left != nullptr) {
        if (nodeToBeDeleted == parent->left)
            parent->left = nodeToBeDeleted->left;
        else
            parent->right = nodeToBeDeleted->left;
    }

    //Case 3
    if (nodeToBeDeleted->left != nullptr && nodeToBeDeleted->right != nullptr) {
        Node *successor = nodeToBeDeleted->right;

        // Find the minimum node in the right subtree
        while (successor->left != nullptr) {
            successor->nrLeftElements--;
            successor = current->left;
        }

        // Replace the value of the head node with the minimum value
        nodeToBeDeleted->value = successor->value;

        // Update the parent's link
        parent = successor->parent;
        parent->left = successor->right;
    }

    nrElems--;
    delete nodeToBeDeleted;
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

    if (relation(e, head->value) && head->left == nullptr) {
        head->nrLeftElements = 1;
        head->left = newNode;
        newNode->parent = head;
        return;
    }

    if (!relation(e, head->value) && head->right == nullptr) {
        head->right = newNode;
        newNode->parent = head;
        return;
    }

    if (relation(e, head->value)) {
        current = head->left;
        head->nrLeftElements++;
    } else {
        current = head->right;
    }

    Node *parent = current;
    while (current != nullptr) {
        parent = current;
        if (relation(e, current->value)) {
            current->nrLeftElements++;
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;
    if (relation(e, parent->value))
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