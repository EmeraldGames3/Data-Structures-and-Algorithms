#include "Node.h"

/**
 * @brief Default constructor of a Node
 * @details The programmer is responsible for initialising these values later
 */
Node::Node() {
    element = {};
    nextNode = nullptr;
    previousNode = nullptr;
}

/**
 * @brief Overloaded constructor with one parameter
 * @param elem The element stored in the node
 * @details The programmer is responsible for initialising the value with a value other then NULL in the future
 */
Node::Node(TElem elem) {
    element = elem;
    nextNode = nullptr;
    previousNode = nullptr;
}

/**
 * @brief Overloaded constructor with Three parameter
 * @param elem The element stored in the node
 * @param next A pointer to the next node, can be NULL
 * @param previous A pointer to the previous node, can be NULL
 * @warning The programmer should be careful if it makes next or previous NULL
 */
Node::Node(TElem elem, Node *next, Node *previous) {
    this->element = elem;
    this->nextNode = next;
    this->previousNode = previous;
}

/**
 * @brief Copy constructor of the class Node
 * @param other An object of type node
 * @warning The programmer should be careful in case that nextNode and/or previousNode are NULL
 */
Node::Node(const Node &other) {
    this->element = other.element;
    this->nextNode = other.nextNode;
    this->previousNode = other.previousNode;
}

/**
 * @brief Destructor of class Node
 * @details Free the dynamically allocated memory
 */
Node::~Node() {
    delete nextNode;
    delete previousNode;
}

/** @brief Getter for the element field */
TElem Node::getElement() const { return element; }

/** @brief Setter for the element field */
void Node::setElement(TElem elem) { this->element = elem; }

/** @brief Getter for the nextNode field */
Node *Node::next() const { return this->nextNode; }

/** @brief Setter for the nextNode field */
void Node::setNextNode(Node *node) { this->nextNode = node; }

/** @brief Getter for the previousNode field */
Node *Node::previous() const { return this->previousNode; }

/** @brief Setter for the previousNode field */
void Node::setPreviousNode(Node *node) { this->previousNode = node; }


