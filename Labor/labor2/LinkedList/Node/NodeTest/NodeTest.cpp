#include "NodeTest.h"
#include "../Node.h"
#include <cassert>
#include <iostream>

void testNode(){
    // Test default constructor
    Node node1;
    assert(node1.getElement() == NULL_TELEM);
    assert(node1.next() == nullptr);
    assert(node1.previous() == nullptr);

    // Test constructor with element parameter
    Node node2(42);
    assert(node2.getElement() == 42);
    assert(node2.next() == nullptr);
    assert(node2.previous() == nullptr);

    // Test constructor with element, next and previous parameters
    Node defaultNode;
    Node node3(7, &defaultNode, &node1);
    assert(node3.getElement() == 7);
    assert(node3.next() == &node1);
    assert(node3.previous() == &defaultNode);

    // Test copy constructor
    Node node4 = node3;
    assert(node4.getElement() == 7);
    assert(node4.next() == &node1);
    assert(node4.previous() == &defaultNode);

    // Test setter and getter for element
    node4.setElement(21);
    assert(node4.getElement() == 21);

    // Test setter and getter for next node
    node4.setNext(&node2);
    assert(node4.next() == &node2);

    // Test setter and getter for previous node
    node4.setPrevious(&node3);
    assert(node4.previous() == &node3);

    // Test destructor
    Node* node5 = new Node(5);
    assert(node5->getElement() == 5);
    delete node5;

    //Test NULL_TELEM behavior
    Node node6 = Node();
    assert(node6.isNULL());
    Node node7 = Node::NULL_NODE();
    assert(node7.isNULL());

    std::cout << "Node test" << std::endl;
}