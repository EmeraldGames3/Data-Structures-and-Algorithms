#include <iostream>
#include "DynamicArray/DynamicArray.h"
#include "DynamicArray/DynamicArray.cpp"
#include "Utils/Random.cpp"
#include "Utils/SortingAlgorithms.cpp"

int main() {
    DynamicArray<int> a;

    a.addToEnd(10);
    a.addToEnd(16);
    a.addToEnd(19);
    a.addToEnd(12);

    a.printArray();

    a.deleteFromEnd();

    a.printArray();

    a.addToPosition(1, 12);
    a.printArray();
    a.deleteFromPosition(1);
    a.printArray();

    a.sortArray();
    a.printArray();

    return 0;
}
