#include <iostream>
#include "IO/IO.h"
#include "SolveLabyrinth/SolveLabyrinth.h"
#include "Queue/QueueTest/ExtendedTest.h"
#include "Queue/QueueTest/ShortTest.h"
#include "Stack/StackTest/StackTest.h"

using namespace std;

/**
 * Solve a labyrinth with bfd
 * @complexityΩ θ(n)
 * @complexityθ θ(n^2)
 * @complexityO θ(n^2)
 */
int main() {
    cout << "Test Queue:\n";
    testAll();
    testAllExtended();
    cout << "\nTest Stack:\n";
    testStack();
    cin.get();

    int rows = 0;
    int columns = 0;
    auto **matrix = readMatrixFromFile("IO/input1.txt", rows, columns);

    printMatrix(matrix, rows, columns);

    auto robotLocation = findRobot(matrix, rows, columns);
    if (robotLocation.column == -1 || robotLocation.row == -1) {
        std::cout << "Robot not found in Labyrinth\n";
        return 0;
    }
    if (robotLocation.column == 0 || robotLocation.row == 0 || robotLocation.row == rows - 1 ||
        robotLocation.column == columns - 1) {
        std::cout << "Robot is already out, no need to solve the labyrinth\n";
        return 0;
    }

    setGoal(matrix, rows, columns);
    printMatrix(matrix, rows, columns);

    if (!exitExists(matrix, rows, columns)) {
        std::cout << "There is no exit out of the labyrinth\n";
        return 0;
    }

    Location pointOfExit;
    auto **previous = new short *[rows];
    for (int i = 0; i < rows; i++) {
        previous[i] = new short[columns];
        for (int j = 0; j < columns; j++) {
            previous[i][j] = Invalid;
        }
    }

    //previous[robotLocation.row][robotLocation.column] = RobotPosition;

    //Perform a breadth first to find the shortest path to the exit if one exists
    if (!breadthFirstSearch(matrix, robotLocation, rows, columns, previous, pointOfExit)) {
        std::cout << "The labyrinth has no exit\n";
        return 0;
    }
    else
        std::cout << "Labyrinth solved\n\n";

    printShortestPath(previous, robotLocation, pointOfExit);

    for (int i = 0; i < rows; i++) {
        delete[] previous[i];
    }
    delete[] previous;
    deallocateMatrix(matrix, rows);
    return 0;
}
