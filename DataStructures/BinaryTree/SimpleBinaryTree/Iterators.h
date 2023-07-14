#pragma once

#include "BinaryTree.h"
#include <stack>
#include <stdexcept>

class BinaryTreeIteratorPreOrder {
    friend class BinaryTree;

private:
    const BinaryTree &binaryTree;
    Node *currentNode;
    std::stack<Node *> stack{};

public:
    explicit BinaryTreeIteratorPreOrder(const BinaryTree &b) : binaryTree(b) {
        currentNode = nullptr;
        first();
    }

    void first() {
        while (!stack.empty()) {
            stack.pop();
        }
        currentNode = binaryTree.root;
        if (currentNode != nullptr) {
            stack.push(currentNode);
        }
    }

    bool isValid() {
        return currentNode != nullptr;
    }

    void next() {
        if (!isValid()) {
            return;
        }

        currentNode = stack.top();
        stack.pop();

        if (currentNode->leftChild != nullptr) {
            stack.push(currentNode->leftChild);
        }
        if (currentNode->rightChild != nullptr) {
            stack.push(currentNode->rightChild);
        }
    }

    TElem getCurrent() {
        if (!isValid()) {
            throw std::logic_error("Iterator is not valid.");
        }

        return currentNode->value;
    }
};

class BinaryTreeIteratorInOrder {
    friend class BinaryTree;

private:
    const BinaryTree &binaryTree;
    Node *currentNode;
    std::stack<Node *> stack{};

public:
    explicit BinaryTreeIteratorInOrder(const BinaryTree &b) : binaryTree(b) {
        currentNode = nullptr;
        first();
    }

    void first() {
        while (!stack.empty()) {
            stack.pop();
        }
        currentNode = binaryTree.root;

        // Perform a left-branch traversal to the leftmost node
        while (currentNode != nullptr) {
            stack.push(currentNode);
            currentNode = currentNode->leftChild;
        }

        if (!stack.empty()) {
            currentNode = stack.top();
            stack.pop();
        }
    }

    bool isValid() {
        return currentNode != nullptr;
    }

    void next() {
        if (!isValid()) {
            return;
        }

        if (currentNode->rightChild != nullptr) {
            currentNode = currentNode->rightChild;

            // Perform a left-branch traversal to the leftmost node
            while (currentNode != nullptr) {
                stack.push(currentNode);
                currentNode = currentNode->leftChild;
            }
        } else if (!stack.empty()) {
            currentNode = stack.top();
            stack.pop();
        } else {
            currentNode = nullptr;
        }
    }

    TElem getCurrent() {
        if (!isValid()) {
            throw std::logic_error("Iterator is not valid.");
        }

        return currentNode->value;
    }
};

class BinaryTreeIteratorPostOrder {
    friend class BinaryTree;

private:
    const BinaryTree &binaryTree;
    Node *currentNode;
    std::stack<Node *> stack{};

public:
    explicit BinaryTreeIteratorPostOrder(const BinaryTree &b) : binaryTree(b) {
        currentNode = nullptr;
        first();
    }

    void first() {
        while (!stack.empty()) {
            stack.pop();
        }
        currentNode = binaryTree.root;

        if (currentNode != nullptr) {
            stack.push(currentNode);
            while (!stack.empty()) {
                Node* node = stack.top();
                if (node->leftChild != nullptr && currentNode != node->leftChild && currentNode != node->rightChild) {
                    stack.push(node->leftChild);
                } else if (node->rightChild != nullptr && currentNode != node->rightChild) {
                    stack.push(node->rightChild);
                } else {
                    currentNode = stack.top();
                    stack.pop();
                    break;
                }
            }
        } else {
            currentNode = nullptr;
        }
    }

    bool isValid() {
        return currentNode != nullptr;
    }

    void next() {
        if (!isValid()) {
            return;
        }

        if (!stack.empty()) {
            Node *topNode = stack.top();
            if (topNode->leftChild != nullptr && currentNode != topNode->leftChild &&
                currentNode != topNode->rightChild) {
                stack.push(topNode->leftChild);
            } else if (topNode->rightChild != nullptr && currentNode != topNode->rightChild) {
                stack.push(topNode->rightChild);
            } else {
                currentNode = topNode;
                stack.pop();
            }
        } else {
            currentNode = nullptr;
        }
    }

    TElem getCurrent() {
        if (!isValid()) {
            throw std::logic_error("Iterator is not valid.");
        }

        return currentNode->value;
    }
};