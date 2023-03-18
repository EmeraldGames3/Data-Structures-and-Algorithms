#include "LinkedList.h"
#include <exception>

/**
 * @brief Default constructor for the DLL class
 * @warning The head and tail are initialised to NULL_NODE
 * @details The programmer is responsible for further initialisation of the DLL
 */
DoubleLinkedList::DoubleLinkedList() : head(Node::NULL_NODE()), tail(Node::NULL_NODE()) {}

/**
 * @brief Overloaded constructor with 1 parameter
 * @param head A node that will represent the head node of the list
 * @warning The head and tail don't point to each other as there is only one object in the list
 * @details The programmer is responsible for further initialisation of the DLL
 **/
DoubleLinkedList::DoubleLinkedList(const Node &head) : head(head), tail(this->head) {}

/**
 * @brief Overloaded constructor with 1 parameter
 * @param elem An object of type TElem
 * @warning The head and tail don't point to each other as there is only one object in the list
 * @details The programmer is responsible for further initialisation of the DLL
 **/
DoubleLinkedList::DoubleLinkedList(TElem elem) : head(Node(elem)), tail(Node(elem)) {}

/**
 * @brief Overloaded constructor with 2 parameters
 * @details Initialises a DLL with 2 elements
 * @param head An object of type Node
 * @param tail An object of type Node
 **/
DoubleLinkedList::DoubleLinkedList(const Node &head, const Node &tail) : head(head), tail(tail) {
    //Avoid copying the pointers of the nodes as we cannot guarantee that the two nodes point to each-other
    this->head.setNext(&(this->tail));
    this->tail.setPrevious(&(this->head));
}

/**
 * @brief Overloaded constructor with 2 parameters
 * @details Initialises a DLL with 2 elements
 * @param head An object of type TElem
 * @param tail An object of type TElem
 **/
DoubleLinkedList::DoubleLinkedList(TElem head, TElem tail) : head(Node(head)), tail(Node(tail)) {
    this->head.setNext(&(this->tail));
    this->tail.setPrevious(&(this->head));
}

/**
 * @brief Copy constructor for the double linked list
 * @param doubleLinkedList A DLL that we want to perform a deep copy of
 **/
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &doubleLinkedList) {
    //TODO Implementation
}

void DoubleLinkedList::addFirst(TElem element) {
    if (isEmpty()) {
        //The DLL is empty
        head = Node(element);
        tail = head;
    }
    else if (head == tail) {
        //DLL has only on element
        head = Node(element);
        head.setNext(&tail);
    }
    else {
        //DLL has at least two elements so we are dealing with dynamically allocated memory
        Node *newNode = new Node(element);
        newNode->setNext(&head);
        head = *newNode;
    }
}

void DoubleLinkedList::addLast(TElem element) {
    if (isEmpty()) {
        //The DLL is empty
        head = Node(element);
        tail = head;
    }
    else if (head == tail) {
        //DLL has only on element
        tail = Node(element);
        tail.setPrevious(&head);
    }
    else {
        //DLL has at least two elements so we are dealing with dynamically allocated memory
        Node *newNode = new Node(element);
        newNode->setPrevious(&tail);
        tail = *newNode;
    }
}

void DoubleLinkedList::deleteFirst() {
    if (isEmpty()) throw std::exception();
    else if (head == tail) {
        //DLL has only on element
        head = Node::NULL_NODE();
        tail = Node::NULL_NODE();
    }
    else if (*head.next() == tail) {
        //DLL has only two elements
        head.setNext(nullptr);
        tail = head;
    }
    else {
        //DLL has more than two elements so we are dealing with dynamically allocated memory
        Node *temp = head.next();
        head = *temp;
        head.setPrevious(nullptr);
        delete temp;
    }
}

void DoubleLinkedList::deleteLast() {
    if (isEmpty()) throw std::exception();
    else if (head == tail) {
        //DLL has only on element
        head = Node::NULL_NODE();
        tail = Node::NULL_NODE();
        return;
    }
    else if (*head.next() == tail) {
        //DLL has only two elements
        head.setNext(nullptr);
        tail = head;
    }

    else {
        //DLL has more than two elements so we are dealing with dynamically allocated memory
        Node *temp = tail.previous();
        tail = *temp;
        tail.setNext(nullptr);
        delete temp;
    }
}

/** @brief Get the head of the the DLL **/
Node DoubleLinkedList::getHeadNode() const { return head; }

/** @brief Get the first element in the DLL **/
TElem DoubleLinkedList::getHead() const { return head.getElement(); }

/** @brief Get the tail of the the DLL **/
Node DoubleLinkedList::getTailNode() const { return tail; }

/** @brief Get the last element in the DLL **/
TElem DoubleLinkedList::getTail() const { return tail.getElement(); }

/** @brief Check if the DLL is empty**/
bool DoubleLinkedList::isEmpty() const { return head.isNULL(); }

/**
 * @brief DLL destructor
 * @details Iterate through the linked list to delete all Nodes
 */
DoubleLinkedList::~DoubleLinkedList() {
    //We have no dynamically allocated memory to delete
    if (head.next() == nullptr) return; //The list has only on element
    if (*head.next() == tail) return; //The list has only two elements

    //TODO iterate through the list and delete dynamically allocated memory
}