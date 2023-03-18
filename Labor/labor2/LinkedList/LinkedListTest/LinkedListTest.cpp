#include "LinkedListTest.h"
#include "../LinkedList.h"
#include <cassert>
#include <iostream>

void testConstructor() {
    DoubleLinkedList dll1;
    assert(dll1.isEmpty());

    Node node1(42);
    DoubleLinkedList dll2(node1);
    assert(dll2.getHead() == node1);
    assert(dll2.getHead() == node1);

    Node node2 = node1;
    Node node3 = Node(43);
    node2.setNext(&node3);
    node3.setPrevious(&node2);
    assert(node2 == *node3.previous());
    assert(*node3.previous() == node2);

    DoubleLinkedList dll3(node2, node3);
    assert(dll3.getHead().getElement() == node2.getElement());
    assert(dll3.getTail().getElement() == node3.getElement());
    assert(dll3.getHead().previous() == nullptr);
    assert(dll3.getTail().next() == nullptr);
    assert(*dll3.getHead().next() == dll3.getTail());
    assert(*dll3.getTail().previous() == dll3.getHead());
}

void testLinkedList() {
    testConstructor();

    std::cout << "Double Linked List test" << std::endl;
}