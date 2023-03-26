#include <iostream>
#include "IO/IO.h"
#include "Queue/QueueTest/ExtendedTest.h"
#include "Queue/QueueTest/ShortTest.h"

using namespace std;

int main() {
    testAll();
    testAllExtended();
//    cin.get();

    int rows = 0;
    int columns = 0;
    char **matrix = readMatrixFromFile("IO/input.txt", rows, columns);

    printMatrix(matrix, rows, columns);
    setGoal(matrix, rows, columns);
    printMatrix(matrix, rows, columns);

    deallocateMatrix(matrix, rows);

    return 0;
}