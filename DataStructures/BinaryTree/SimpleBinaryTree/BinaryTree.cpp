#include <iostream>
#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    root = nullptr;
    nrElems = 0;
}

BinaryTree::~BinaryTree() {
    Node **nodeStack = new Node *[nrElems];
    int top = -1;

    Node *current = root;
    Node *lastVisited = nullptr;

    while (current != nullptr || top != -1) {
        if (current) {
            nodeStack[++top] = current;
            current = current->leftChild;
        } else {
            Node *peekNode = nodeStack[top];

            if (peekNode->rightChild && lastVisited != peekNode->rightChild) {
                current = peekNode->rightChild;
            } else {
                top--;
                lastVisited = peekNode;
                delete peekNode;
            }
        }
    }

    delete[] nodeStack;
}

void BinaryTree::addLeft(TElem elem) {
    Node *newNode = new Node{elem, nullptr, nullptr, nullptr};
    if(root == nullptr){
        root = newNode;
        nrElems = 1;
        return;
    }

    Node *currentNode = root;
    while (currentNode->leftChild != nullptr && currentNode->rightChild != nullptr){
        currentNode = currentNode->leftChild;
    }

    newNode->parent = currentNode;
    if(currentNode->leftChild == nullptr){
        currentNode->leftChild = newNode;
    } else {
        currentNode->rightChild = newNode;
    }
    nrElems++;
}

void BinaryTree::addRight(TElem elem) {
    Node *newNode = new Node{elem, nullptr, nullptr, nullptr};
    if(root == nullptr){
        root = newNode;
        nrElems = 1;
        return;
    }

    Node *currentNode = root;
    while (currentNode->leftChild != nullptr && currentNode->rightChild != nullptr){
        currentNode = currentNode->rightChild;
    }

    newNode->parent = currentNode;
    if(currentNode->leftChild == nullptr){
        currentNode->leftChild = newNode;
    } else {
        currentNode->rightChild = newNode;
    }
    nrElems++;
}

int BinaryTree::size() const {
    return nrElems;
}

void BinaryTree::printTreeInOrder() {
    // Call the recursive helper function to perform in-order traversal
    inOrderTraversal(root);

    std::cout << std::endl;
}

void BinaryTree::inOrderTraversal(Node* node) {
    if (node == nullptr)
        return;

    // Traverse the left subtree
    inOrderTraversal(node->leftChild);

    // Print the current node's value
    std::cout << node->value << " ";

    // Traverse the right subtree
    inOrderTraversal(node->rightChild);
}

void BinaryTree::remove(TElem elem) {
    Node* currentNode = root;
    Node* parentNode = nullptr;
    bool found = false;

    while (currentNode != nullptr) {
        if (elem < currentNode->value) {
            parentNode = currentNode;
            currentNode = currentNode->leftChild;
        } else if (elem > currentNode->value) {
            parentNode = currentNode;
            currentNode = currentNode->rightChild;
        } else {
            found = true;
            break;
        }
    }

    if (!found)
        return;  // Element not found in the tree

    if (currentNode->leftChild == nullptr && currentNode->rightChild == nullptr) {
        // Case 1: Node has no children (leaf node)
        if (parentNode == nullptr) {
            // Node is the root
            root = nullptr;
        } else if (parentNode->leftChild == currentNode) {
            parentNode->leftChild = nullptr;
        } else {
            parentNode->rightChild = nullptr;
        }
        delete currentNode;
    } else if (currentNode->leftChild == nullptr) {
        // Case 2: Node has only a right child
        if (parentNode == nullptr) {
            // Node is the root
            root = currentNode->rightChild;
            root->parent = nullptr;
        } else if (parentNode->leftChild == currentNode) {
            parentNode->leftChild = currentNode->rightChild;
            currentNode->rightChild->parent = parentNode;
        } else {
            parentNode->rightChild = currentNode->rightChild;
            currentNode->rightChild->parent = parentNode;
        }
        delete currentNode;
    } else if (currentNode->rightChild == nullptr) {
        // Case 3: Node has only a left child
        if (parentNode == nullptr) {
            // Node is the root
            root = currentNode->leftChild;
            root->parent = nullptr;
        } else if (parentNode->leftChild == currentNode) {
            parentNode->leftChild = currentNode->leftChild;
            currentNode->leftChild->parent = parentNode;
        } else {
            parentNode->rightChild = currentNode->leftChild;
            currentNode->leftChild->parent = parentNode;
        }
        delete currentNode;
    } else {
        // Case 4: Node has both left and right children
        Node* minRightSubtree = currentNode->rightChild;
        while (minRightSubtree->leftChild != nullptr) {
            minRightSubtree = minRightSubtree->leftChild;
        }

        currentNode->value = minRightSubtree->value;

        if (minRightSubtree->parent->leftChild == minRightSubtree) {
            minRightSubtree->parent->leftChild = minRightSubtree->rightChild;
        } else {
            minRightSubtree->parent->rightChild = minRightSubtree->rightChild;
        }

        if (minRightSubtree->rightChild != nullptr) {
            minRightSubtree->rightChild->parent = minRightSubtree->parent;
        }

        delete minRightSubtree;
    }
}