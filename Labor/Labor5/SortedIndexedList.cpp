#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
#include <exception>

using namespace std;

/**
* @brief SortedIndexedList constructor
* @complexity θ(1)
**/
SortedIndexedList::SortedIndexedList(Relation r) {
    relation = r; //relation(e, value) == e <= value
    nrElems = 0;
    head = nullptr;
}

/**
* @brief Get the size of the list
* @complexity θ(1)
**/
int SortedIndexedList::size() const {
    return nrElems;
}

/**
* @brief Check if the list is empty
* @complexity θ(1)
**/
bool SortedIndexedList::isEmpty() const {
    return nrElems == 0;
}

/**
* @brief Get an element from the list
* @complexityΩ θ(1)
* @complexityθ θ(log n)
* @complexityO θ(n)
**/
TComp SortedIndexedList::getElement(int pos) const {
    if (isEmpty())
        throw exception();

    if (pos < 0 || pos >= nrElems)
        throw exception();

    Node *current = head;
    int currentPosition = head->nrLeftElements;

    while (current != nullptr) {
        if (currentPosition == pos)
            return current->value;

        if (pos < currentPosition) {
            current = current->left;
            if (current != nullptr)
                currentPosition -= (current->parent->nrLeftElements - current->nrLeftElements);
        } else {
            current = current->right;
            if (current != nullptr)
                currentPosition += (current->nrLeftElements + 1);
        }
    }

    throw exception();
}

/**
* @brief Remove an element from the list
* @complexityΩ θ(1)
* @complexityθ θ(log n)
* @complexityO θ(n)
**/
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
            Node *nextNode = head->right;

            while (nextNode->left != nullptr) {
                nextNode->nrLeftElements--;
                nextNode = nextNode->left;
            }

            head->value = nextNode->value;
            Node *parent = nextNode->parent;

            if (parent == head) {
                parent->right = nextNode->right;
                if (nextNode->right != nullptr)
                    (nextNode->right)->parent = parent;
            } else {
                parent->left = nextNode->right;
                if (nextNode->right != nullptr)
                    (nextNode->right)->parent = parent;
            }

            delete nextNode;
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
            Node *nextNode = current->right;

            while (nextNode->left != nullptr) {
                nextNode->nrLeftElements--;
                nextNode = nextNode->left;
            }

            current->value = nextNode->value;
            parent = nextNode->parent;

            if (parent == current) {
                parent->right = nextNode->right;
                if (nextNode->right != nullptr)
                    (nextNode->right)->parent = parent;
            } else {
                parent->left = nextNode->right;
                if (nextNode->right != nullptr)
                    (nextNode->right)->parent = parent;
            }

            delete nextNode;
        }
    }

    nrElems--;
    return deletedValue;
}

/**
* @brief Search an element in the list
* @complexityΩ θ(1)
* @complexityθ θ(log n)
* @complexityO θ(n)
**/
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

/**
* @brief Add an element in the list
* @complexityΩ θ(1)
* @complexityθ θ(log n)
* @complexityO θ(n)
**/
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

/**
* @brief Create an iterator
* @complexity θ(1)
**/
ListIterator SortedIndexedList::iterator() {
    return ListIterator(*this);
}

/**
* @brief List destructor
* @complexity θ(n)
**/
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

/**
* @brief Delete the element k, k * 2, k * 3, ...
* @complexityΩ θ(1)
* @complexityθ θ(n)
* @complexityO θ(n)
**/
void SortedIndexedList::deleteKElement(int k) {
    /*
     *  if k < 0 or k > nrElems - 1:
     *      raise exception;
     *
     *  if k = 0:
     *      node = @findMinimumInTree
     *      @deallocate(node)
     *      nrElements = nrElements - 1
     *      return;
     *
     *  if k = 1:
     *      newHead = allocateNode((@findMinimumInTree)->value)
     *      @deleteAllNodes
     *
     *      head = newHead
     *      nrElements = 1
     *      return;
     *
     *  while current != NULL:
     *      current = @searchForNodeByPosition(k)
     *      next = current
     *
     *      for(i = 0; i < k; i++):
     *          next = @findSuccessor(next)
     *          if next = NULL:
     *              break
     *
     *      @deallocate(current)
     *      current = next
     *      nrElements = nrElements - 1;
     */

    if (k < 0 || k > nrElems - 1)
        throw exception();

    if(k == 0){
        Node *current = head;

        while (current->left != nullptr) {
            current = current->left;
        }

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
                Node *nextNode = head->right;

                while (nextNode->left != nullptr) {
                    nextNode->nrLeftElements--;
                    nextNode = nextNode->left;
                }

                head->value = nextNode->value;
                Node *parent = nextNode->parent;

                if (parent == head) {
                    parent->right = nextNode->right;
                    if (nextNode->right != nullptr)
                        (nextNode->right)->parent = parent;
                } else {
                    parent->left = nextNode->right;
                    if (nextNode->right != nullptr)
                        (nextNode->right)->parent = parent;
                }

                delete nextNode;
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
                Node *nextNode = current->right;

                while (nextNode->left != nullptr) {
                    nextNode->nrLeftElements--;
                    nextNode = nextNode->left;
                }

                current->value = nextNode->value;
                parent = nextNode->parent;

                if (parent == current) {
                    parent->right = nextNode->right;
                    if (nextNode->right != nullptr)
                        (nextNode->right)->parent = parent;
                } else {
                    parent->left = nextNode->right;
                    if (nextNode->right != nullptr)
                        (nextNode->right)->parent = parent;
                }

                delete nextNode;
            }
        }

        nrElems--;
        if(head != nullptr)
            head->nrLeftElements--;
        return;
    }

    if(k == 1){
        Node *current = head;

        while (current->left != nullptr){
            current = current->left;
        }

        Node *newHead = new Node{current->value};

        Node **nodeStack = new Node *[nrElems];
        int top = -1;

        current = head;
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
        head = newHead;
        nrElems = 1;
        return;
    }

    Node *current = head;
    Node *next;
    int currentPosition = head->nrLeftElements;

    while (currentPosition != k) {
        if (k < currentPosition) {
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

    next = current;
    while (current != nullptr){
        current = next;

        for(int i = 0; i < k; i++){
            if (next->right != nullptr) {
                next = next->right;
                while (next->left != nullptr) {
                    next = next->left;
                }
            } else {
                Node *parent = next->parent;
                while (parent != nullptr && parent->left != next) {
                    next = parent;
                    parent = next->parent;
                }
                next = parent;
            }

            if(next == nullptr){
                break;
            }
        }

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
                Node *nextNode = head->right;

                while (nextNode->left != nullptr) {
                    nextNode->nrLeftElements--;
                    nextNode = nextNode->left;
                }

                head->value = nextNode->value;
                Node *parent = nextNode->parent;

                if (parent == head) {
                    parent->right = nextNode->right;
                    if (nextNode->right != nullptr)
                        (nextNode->right)->parent = parent;
                } else {
                    parent->left = nextNode->right;
                    if (nextNode->right != nullptr)
                        (nextNode->right)->parent = parent;
                }

                delete nextNode;
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
                Node *nextNode = current->right;

                while (nextNode->left != nullptr) {
                    nextNode->nrLeftElements--;
                    nextNode = nextNode->left;
                }

                current->value = nextNode->value;
                parent = nextNode->parent;

                if (parent == current) {
                    parent->right = nextNode->right;
                    if (nextNode->right != nullptr)
                        (nextNode->right)->parent = parent;
                } else {
                    parent->left = nextNode->right;
                    if (nextNode->right != nullptr)
                        (nextNode->right)->parent = parent;
                }

                delete nextNode;
            }
        }
        nrElems--;

        if(next == nullptr)
            break;
    }
}