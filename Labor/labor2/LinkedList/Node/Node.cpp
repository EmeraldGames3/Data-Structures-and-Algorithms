#include "Node.h"

/**
 * @brief Default constructor of a Node
 * @warning This constructor initialises the node as a NULL_NODE
 * @details The programmer is responsible for initialising these values later
 **/
Node::Node() : element(NULL_TELEM), previousNode(nullptr), nextNode(nullptr) {}

/**
 * @brief Overloaded constructor with one parameter
 * @param elem The element stored in the node
 * @details The programmer is responsible for initialising the value with a value other then NULL in the future
 **/
Node::Node(TElem elem) : element(elem), previousNode(nullptr), nextNode(nullptr) {}

/**
 * @brief Overloaded constructor with Three parameter
 * @param elem The element stored in the node
 * @param next A pointer to the next node, can be NULL
 * @param previous A pointer to the previous node, can be NULL
 * @warning The programmer should be careful if it makes next or previous NULL
 **/
Node::Node(TElem elem, Node *previous, Node *next) : element(elem), previousNode(previous), nextNode(next) {}

/**
 * @brief Copy constructor of the class Node
 * @param other An object of type node
 * @warning The programmer should be careful in case that nextNode and/or previousNode are NULL
 **/
Node::Node(const Node &other) : element(other.element) {
    this->nextNode = other.nextNode;
    this->previousNode = other.previousNode;
}

/** @brief Destructor of class Node **/
Node::~Node() = default;

/** @brief Getter for the element field **/
TElem Node::getElement() const { return element; }

/** @brief Setter for the element field **/
void Node::setElement(TElem elem) { this->element = elem; }

/** @brief Getter for the nextNode field **/
Node *Node::next() const { return this->nextNode; }

/** @brief Setter for the nextNode field **/
void Node::setNext(Node *node) { this->nextNode = node; }

/** @brief Getter for the previousNode field **/
Node *Node::previous() const { return this->previousNode; }

/** @brief Setter for the previousNode field **/
void Node::setPrevious(Node *node) { this->previousNode = node; }

/**
 * @brief Create a NULL_NODE
 * @warning The programmer should be careful when using a NULL_NODE as all its parameters are NULL
 **/
Node Node::NULL_NODE() {
    return {NULL_TELEM, nullptr, nullptr};
}

/** @brief Check if the node is NULL **/
bool Node::isNULL() const {
    if (this->element == NULL_TELEM && this->previousNode == nullptr && this->nextNode == nullptr)
        return true;
    return false;
}

/** @brief Overload the == operator for the class Node **/
bool Node::operator==(Node &other) {
    if (this->element != other.element) return false;
    if (this->previousNode != other.previousNode) return false;
    if (this->nextNode != other.nextNode) return false;
    return true;
}