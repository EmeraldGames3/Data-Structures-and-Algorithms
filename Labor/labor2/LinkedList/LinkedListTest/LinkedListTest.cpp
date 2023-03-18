#include "LinkedListTest.h"
#include "../LinkedList.h"
#include <cassert>
#include <iostream>

void testConstructor1() {
    //Test the constructors that receive Nodes as parameters

    //Test default constructor
    DoubleLinkedList dll1;
    assert(dll1.isEmpty());

    //Test constructor with one parameter
    Node node1(42);
    DoubleLinkedList dll2(node1);
    assert(dll2.getHeadNode() == node1);
    assert(dll2.getHeadNode() == node1);

    //Tests for the node class
    Node node2 = node1;
    Node node3 = Node(43);
    node2.setNext(&node3);
    node3.setPrevious(&node2);
    assert(node2 == *node3.previous());
    assert(*node3.previous() == node2);

    //Test constructor with 2 parameters
    DoubleLinkedList dll3(node2, node3);
    assert(dll3.getHeadNode().getElement() == node2.getElement());
    assert(dll3.getTailNode().getElement() == node3.getElement());
    assert(dll3.getHeadNode().previous() == nullptr);
    assert(dll3.getTailNode().next() == nullptr);
    assert(*dll3.getHeadNode().next() == dll3.getTailNode());
    assert(*dll3.getTailNode().previous() == dll3.getHeadNode());
}

void testConstructor2(){
    //Test the constructors that receive TElems as parameters

    //Test constructor with 1 parameter
    DoubleLinkedList dll1(42);
    assert(!dll1.isEmpty());
    assert(dll1.getHead() == 42);
    assert(dll1.getTail() == 42);

    //Test constructor with 2 parameters
    DoubleLinkedList dll(1, 2);
    assert(!dll.isEmpty());
    assert(dll.getHead() == 1);
    assert(dll.getTail() == 2);
    assert(*dll.getHeadNode().next() == dll.getTailNode());
    assert(*dll.getTailNode().previous() == dll.getHeadNode());
}

void testAddFirst() {
    DoubleLinkedList list;
    list.addFirst(1);
    assert(list.getHead() == 1);
    assert(list.getTail() == 1);
    list.addFirst(2);
    assert(list.getHead() == 2);
    assert(list.getTail() == 1);
    list.addFirst(3);
    assert(list.getHead() == 3);
    assert(list.getTail() == 1);
}

void testAddLast() {
    DoubleLinkedList list;
    list.addLast(1);
    assert(list.getHead() == 1);
    assert(list.getTail() == 1);
    list.addLast(2);
    assert(list.getHead() == 1);
    assert(list.getTail() == 2);
    list.addLast(3);
    assert(list.getHead() == 1);
    assert(list.getTail() == 3);
}

void testDeleteFirst() {
    DoubleLinkedList list;
    list.addFirst(1);
    list.deleteFirst();
    assert(list.isEmpty());
    list.addFirst(1);
    list.addFirst(2);
    list.deleteFirst();
    assert(list.getHead() == 1);
    assert(list.getTail() == 1);
    list.addFirst(2);
    list.addFirst(3);
    list.deleteFirst();
    assert(list.getHead() == 2);
    assert(list.getTail() == 1);
}

void testDeleteLast() {
    DoubleLinkedList list;
    list.addFirst(1);
    list.deleteLast();
    assert(list.isEmpty());
    list.addFirst(1);
    list.addFirst(2);
    list.deleteLast();
    assert(list.getHead() == 2);
    assert(list.getTail() == 2);
    list.addLast(3);
    list.addLast(4);
    list.deleteLast();
    assert(list.getHead() == 2);
    assert(list.getTail() == 3);
}


void testLinkedList() {
    testConstructor1();
    testConstructor2();
    testAddFirst();
    testAddLast();
    testDeleteFirst();
    testDeleteLast();

    std::cout << "DLL test" << std::endl;
}