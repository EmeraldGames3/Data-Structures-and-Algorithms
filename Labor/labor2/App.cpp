#include <iostream>
#include "LocationQueue/Queue.h"
#include "Queue/QueueTest/ExtendedTest.h"
#include "Queue/QueueTest/ShortTest.h"
#include "IO/IO.h"
#include "Robot/Robot.h"

using namespace std;

int main() {
//    testAll();
//    testAllExtended();
    cout << "\n";
//    cin.get();

    int rows = 0;
    int columns = 0;
    char **matrix = readMatrixFromFile("IO/input.txt", rows, columns);
    printMatrix(matrix, rows, columns);

    Queue path;
    auto robotLocation = findRobot(matrix, rows, columns);
//    path.push(robotLocation);

    cout << robotLocation.getRow() << " " << robotLocation.getColumn();

    deallocateMatrix(matrix, rows, columns);

    return 0;
}