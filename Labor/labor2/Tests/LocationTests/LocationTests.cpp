#include <cassert>
#include <exception>
#include <iostream>
#include "../../LocationQueue/Location/Location.h"

void testLocationConstructor() {
    Location loc1;
    assert(loc1.getRow() == -1 && loc1.getColumn() == -1);

    Location loc2(3, 4);
    assert(loc2.getRow() == 3 && loc2.getColumn() == 4);
}

void testLocationCopyConstructor() {
    Location loc1(2, 5);
    Location loc2(loc1);
    assert(loc2.getRow() == 2 && loc2.getColumn() == 5);
}

void testLocationGetters() {
    Location loc(3, 4);
    assert(loc.getRow() == 3);
    assert(loc.getColumn() == 4);
}

void testLocationSetters() {
    Location loc;
    loc.setRow(3);
    loc.setColumn(4);
    assert(loc.getRow() == 3 && loc.getColumn() == 4);

    try {
        loc.setRow(-2); //invalid row value
        assert(false); //if exception is not thrown, the test fails
    } catch (std::exception& e) {
        assert(true);
    }

    try {
        loc.setColumn(-2); //invalid column value
        assert(false); //if exception is not thrown, the test fails
    } catch (std::exception& e) {
        assert(true);
    }
}

void testLocationEqualityOperator() {
    Location loc1(3, 4);
    Location loc2(3, 4);
    Location loc3(2, 4);
    Location loc4(3, 5);

    assert(loc1 == loc2);
    assert(!(loc1 == loc3));
    assert(!(loc1 == loc4));
}

void testLocationAssignmentOperator() {
    Location loc1(3, 4);
    Location loc2;
    loc2 = loc1;
    assert(loc2.getRow() == 3 && loc2.getColumn() == 4);

    loc2 = Location(2, 5);
    assert(loc2.getRow() == 2 && loc2.getColumn() == 5);
}

void testLocation() {
    testLocationConstructor();
    testLocationCopyConstructor();
    testLocationGetters();
    testLocationSetters();
    testLocationEqualityOperator();
    testLocationAssignmentOperator();

    std::cout << "Test Location\n";
}
