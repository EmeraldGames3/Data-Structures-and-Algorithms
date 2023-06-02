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
        nrElems = 0;
        delete deletedNode;
        head = nullptr;
        return deletedValue;
    }


}

int SortedIndexedList::search(TComp e) const {
    if(isEmpty())
        return -1;

    Node *current = head;
    int position = head->nrLeftElements;

    while (current != nullptr){
        if(current->value == e){
            return position;
        }
        if(relation(e, current->value)){
            current = current->left;
            if(current != nullptr)
                position -= (current->parent->nrLeftElements - current->nrLeftElements);
        } else{
            current = current->right;
            if(current != nullptr)
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

    if(relation(e, head->value) && head->left == nullptr){
        head->nrLeftElements = 1;
        head->left = newNode;
        newNode->parent = head;
        return;
    }

    if(!relation(e, head->value) && head->right == nullptr){
        head->right = newNode;
        newNode->parent = head;
        return;
    }

    if(relation(e, head->value)){
        current = head->left;
        head->nrLeftElements++;
    }
    else{
        current = head->right;
    }

    Node *parent = current;
    while (current != nullptr){
        parent = current;
        if(relation(e, current->value)){
            current->nrLeftElements++;
            current = current->left;
        } else{
            current = current->right;
        }
    }

    newNode->parent = parent;
    if(relation(e, parent->value))
        parent->left = newNode;
    else
        parent->right = newNode;
}

ListIterator SortedIndexedList::iterator() {
    return ListIterator(*this);
}

SortedIndexedList::~SortedIndexedList() {
    Node** nodeStack = new Node*[nrElems];
    int top = -1;

    Node* current = head;
    Node* lastVisited = nullptr;

    while (current != nullptr || top != -1) {
        if (current) {
            nodeStack[++top] = current;
            current = current->left;
        } else {
            Node* peekNode = nodeStack[top];

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