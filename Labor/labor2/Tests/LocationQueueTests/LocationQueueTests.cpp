#include <cassert>
#include <iostream>
#include "../../LocationQueue/LocationQueue.h"

void testCopyConstructor() {
    LocationQueue q1;
    q1.push(Location(1, 2));
    q1.push(Location(3, 4));
    q1.push(Location(5, 6));

    LocationQueue q2(q1);

    assert(q1.pop() == Location(1, 2));
    assert(q1.pop() == Location(3, 4));
    assert(q1.pop() == Location(5, 6));
    assert(q1.isEmpty());

    assert(q2.pop() == Location(1, 2));
    assert(q2.pop() == Location(3, 4));
    assert(q2.pop() == Location(5, 6));
    assert(q2.isEmpty());
}

void testAssignmentOperator() {
    LocationQueue q1;
    q1.push(Location(1, 2));
    q1.push(Location(3, 4));
    q1.push(Location(5, 6));

    LocationQueue q2;
    q2.push(Location(7, 8));
    q2.push(Location(9, 10));

    q2 = q1;

    assert(q1.pop() == Location(1, 2));
    assert(q1.pop() == Location(3, 4));
    assert(q1.pop() == Location(5, 6));
    assert(q1.isEmpty());

    assert(q2.pop() == Location(1, 2));
    assert(q2.pop() == Location(3, 4));
    assert(q2.pop() == Location(5, 6));
    assert(q2.isEmpty());
}

void testPushAndPop(){
    LocationQueue q;

    assert(q.isEmpty());

    // Test pushing an element to the queue
    Location l1(0, 0);
    q.push(l1);
    assert(!q.isEmpty());
    assert(q.top() == l1);

    // Test pushing another element to the queue
    Location l2(1, 1);
    q.push(l2);
    assert(!q.isEmpty());
    assert(q.top() == l1);

    // Test popping an element from the queue
    assert(q.pop() == l1);
    assert(!q.isEmpty());
    assert(q.top() == l2);

    // Test pushing and popping multiple elements
    Location l3(2, 2);
    Location l4(3, 3);
    q.push(l3);
    q.push(l4);
    assert(!q.isEmpty());
    assert(q.top() == l2);
    assert(q.pop() == l2);
    assert(!q.isEmpty());
    assert(q.top() == l3);
    assert(q.pop() == l3);
    assert(!q.isEmpty());
    assert(q.top() == l4);
    assert(q.pop() == l4);

    // Test throwing an exception when popping from an empty queue
    assert(q.isEmpty());
    try {
        q.pop();
        assert(false);
    } catch (...) {
        assert(true);
    }
}

void testLocationQueue() {
    testPushAndPop();
    testAssignmentOperator();
    testCopyConstructor();

    std::cout << "TestLocationQueue\n";
}