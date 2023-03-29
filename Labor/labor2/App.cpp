#include <iostream>
#include "Queue/Queue.h"
#include "IO/IO.h"
#include "Queue/QueueTest/ExtendedTest.h"
#include "Queue/QueueTest/ShortTest.h"

using namespace std;

enum MatrixStates {
    Wall = 'X',
    Robot = 'R',
    Visited = 'V',
    Path = '*',
    Goal = 'G',
    PointOfExit = 'E'
};

struct Location {
    int row;
    int column;

    Location(int i, int j) : row(i), column(j) {}
};

Location findRobot(char **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] == Robot)
                return {i, j};
        }
    }

    return {-1, -1};
}

bool exitExists(char **matrix, int rows, int columns) {
    for (int j = 0; j < columns; j++)
        if (matrix[0][j] == Goal || matrix[rows - 1][j] == Goal)
            return true;

    for (int i = 0; i < rows; i++)
        if (matrix[i][columns - 1] == Goal || matrix[i][0] == Goal)
            return true;

    return false;
}

int main() {
    testAll();
    testAllExtended();

    int rows = 0;
    int columns = 0;
    auto **matrix = readMatrixFromFile("IO/input.txt", rows, columns);

    printMatrix(matrix, rows, columns);

    setGoal(matrix, rows, columns);

    printMatrix(matrix, rows, columns);

    auto robotLocation = findRobot(matrix, rows, columns);

    if (robotLocation.column == -1 || robotLocation.row == -1) {
        std::cout << "Robot not found in Labyrinth\n";
        return 0;
    }

    if (!exitExists(matrix, rows, columns)) {
        std::cout << "There is no exit out of the labyrinth\n";
        return 0;
    }

    if (robotLocation.column == 0 || robotLocation.row == 0 || robotLocation.row == rows - 1 ||
        robotLocation.column == columns - 1) {
        std::cout << "Robot is already out, no need to solve the labyrinth\n";
        return 0;
    }

    enum Directions {
        North = 0,
        South = 1,
        West = 2,
        East = 3
    };
    auto robotPath = Queue();

    Location currentLocation = Location(robotLocation.row, robotLocation.column);

    while (!robotPath.isEmpty()) {
        int row = currentLocation.row;
        int column = currentLocation.column;

        if (matrix[row][column] == Goal) {
            std::cout << "Robot has reached the exit!\n\n";
            break;
        }

        if (matrix[row][column] != Visited) {
            // Visit the current location
            matrix[row][column] = Visited;

            // Visit the neighbours
            if (column > 0 && matrix[row][column - 1] != Wall) {
                robotPath.push(North);
            }
            if (column < columns - 1 && matrix[row][column + 1] != Wall) {
                robotPath.push(South);
            }
            if (row > 0 && matrix[row - 1][column] != Wall) {
                robotPath.push(East);
            }
            if (row < rows - 1 && matrix[row + 1][column] != Wall) {
                robotPath.push(West);
            }
        }
    }

    printMatrix(matrix, rows, columns);

    deallocateMatrix(matrix, rows);
    return 0;
}
