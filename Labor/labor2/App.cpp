#include <iostream>
#include <stack>
#include "IO/IO.h"
#include "SolveLabyrinth/SolveLabyrinth.h"
#include "Queue/QueueTest/ExtendedTest.h"
#include "Queue/QueueTest/ShortTest.h"

using namespace std;

void printShortestPath(short **previous, Location robotLocation, Location pointOfExit) {
    Location currentLocation = pointOfExit;

    std::stack<Directions> stack1;
    while (currentLocation.column != robotLocation.column || currentLocation.row != robotLocation.row) {
//        std::cout << currentLocation.row << ' ' << currentLocation.column << ' ';
        switch (previous[currentLocation.row][currentLocation.column]) {
            case North:
                currentLocation = Location(currentLocation.row - 1, currentLocation.column);
                stack1.push(South);
                break;
            case South:
                currentLocation = Location(currentLocation.row + 1, currentLocation.column);
                stack1.push(North);
                break;
            case East:
                currentLocation = Location(currentLocation.row, currentLocation.column - 1);
                stack1.push(East);
                break;
            case West:
                currentLocation = Location(currentLocation.row, currentLocation.column + 1);
                stack1.push(West);
                break;
            default:
                throw exception();
        }
    }

    std::cout << "\nThe shortest path towards the exit of the labyrinth is:\n";
    while (!stack1.empty()) {
        int current = stack1.top();
        stack1.pop();

        switch (current) {
            case North:
                std::cout << "North ";
                break;
            case South:
                std::cout << "South ";
                break;
            case West:
                std::cout << "West ";
                break;
            case East:
                std::cout << "East ";
                break;
            default:
                break;
        }
    }
}

int main() {
    testAll();
    testAllExtended();

    int rows = 0;
    int columns = 0;
    auto **matrix = readMatrixFromFile("IO/input1.txt", rows, columns);

    printMatrix(matrix, rows, columns);
    setGoal(matrix, rows, columns);
    printMatrix(matrix, rows, columns);

    auto robotLocation = findRobot(matrix, rows, columns);

    if (robotLocation.column == -1 || robotLocation.row == -1) {
        std::cout << "Robot not found in Labyrinth\n";
        return 0;
    } else if (!exitExists(matrix, rows, columns)) {
        std::cout << "There is no exit out of the labyrinth\n";
        return 0;
    } else if (robotLocation.column == 0 || robotLocation.row == 0 || robotLocation.row == rows - 1 ||
               robotLocation.column == columns - 1) {
        std::cout << "Robot is already out, no need to solve the labyrinth\n";
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

//    previous[robotLocation.row][robotLocation.column] = RobotPosition;

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
