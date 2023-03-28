#include <iostream>
#include "Queue/Queue.h"
#include "IO/IO.h"
#include "Queue/QueueTest/ExtendedTest.h"
#include "Queue/QueueTest/ShortTest.h"

using namespace std;

enum Directions {
    North = 0,
    South = 1,
    West = 2,
    East = 3
};

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

void visitNeighbours(char **matrix, int i, int j) {
    if (matrix[i - 1][j] != Wall && matrix[i - 1][j] != Visited) {
        matrix[i - 1][j] = Visited;
    }
    if (matrix[i + 1][j] != Wall && matrix[i - 1][j] != Visited) {
        matrix[i + 1][j] = Visited;
    }
    if (matrix[i][j - 1] != Wall && matrix[i - 1][j] != Visited) {
        matrix[i][j - 1] = Visited;
    }
    if (matrix[i][j + 1] != Wall && matrix[i - 1][j] != Visited) {
        matrix[i][j + 1] = Visited;
    }
}

int main() {
    testAll();
    testAllExtended();
//    cin.get();

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

    std::cout << "Robot found at location: " << robotLocation.row << ' ' << robotLocation.column << "\n\n";
    matrix[robotLocation.row][robotLocation.column] = Visited;

    printMatrix(matrix, rows, columns);

    auto robotPath = Queue();

    int previous[rows][columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            previous[i][j] = -1;
        }
    }

    Location lastVisited = Location(-1, -1);
    bool solved = false;
    while (!solved) {
        bool updated = false;
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < columns - 1; j++) {
                if (matrix[i][j] == Visited) {
                    if (matrix[i - 1][j] == Goal || matrix[i + 1][j] == Goal || matrix[i][j - 1] == Goal ||
                        matrix[i][j + 1] == Goal) {
                        matrix[i][j] = PointOfExit;
                        lastVisited = Location(i, j);
                        solved = true;
                    } else if (matrix[i - 1][j] != Wall && matrix[i - 1][j] != Visited) {
                        matrix[i - 1][j] = Visited;
                        updated = true;
                        robotPath.push(Directions::North);
                        previous[i - 1][j] = i * columns + j;
                        i--;
                        break;
                    } else if (matrix[i + 1][j] != Wall && matrix[i + 1][j] != Visited) {
                        matrix[i + 1][j] = Visited;
                        updated = true;
                        robotPath.push(Directions::South);
                        previous[i + 1][j] = i * columns + j;
                        i--;
                        break;
                    } else if (matrix[i][j - 1] != Wall && matrix[i][j - 1] != Visited) {
                        matrix[i][j - 1] = Visited;
                        updated = true;
                        robotPath.push(Directions::East);
                        previous[i][j - 1] = i * columns + j;
                        j--;
                    } else if (matrix[i][j + 1] != Wall && matrix[i][j + 1] != Visited) {
                        matrix[i][j + 1] = Visited;
                        updated = true;
                        robotPath.push(Directions::West);
                        previous[i][j + 1] = i * columns + j;
                        j--;
                    }
                }
            }
        }
        if (!updated) {
            std::cout << "There is no exit out of the labyrinth\n";
            deallocateMatrix(matrix, rows);
            return 0;
        }
        printMatrix(matrix, rows, columns);
    }

    matrix[robotLocation.row][robotLocation.column] = 'R';

    printMatrix(matrix, rows, columns);

    Location pointOfExit(-1, -1);

    if (matrix[lastVisited.row + 1][lastVisited.column] == 'G') {
        pointOfExit.row = lastVisited.row + 1;
        pointOfExit.column = lastVisited.column;
    } else if (matrix[lastVisited.row][lastVisited.column + 1] == 'G') {
        pointOfExit.row = lastVisited.row;
        pointOfExit.column = lastVisited.column + 1;
    } else if (matrix[lastVisited.row - 1][lastVisited.column] == 'G') {
        pointOfExit.row = lastVisited.row - 1;
        pointOfExit.column = lastVisited.column;
    } else {
        pointOfExit.row = lastVisited.row;
        pointOfExit.column = lastVisited.column - 1;
    }

    std::cout << "Robot exited from " << lastVisited.column << ' ' << lastVisited.row << " towards the exit at "
              << pointOfExit.row << ' ' << pointOfExit.column << '\n';

    // print shortest path to exit
    std::cout << "Shortest path to exit: ";
    int exitRow = pointOfExit.row, exitCol = pointOfExit.column;

    for (int i = exitRow * columns + exitCol;
         previous[i / columns][i % columns] != -1; i = previous[i / columns][i % columns]) {
        if (previous[i / columns][i % columns] == i - 1) {
            robotPath.push(Directions::West);
        } else if (previous[i / columns][i % columns] == i + 1) {
            robotPath.push(Directions::East);
        } else if (previous[i / columns][i % columns] == i - columns) {
            robotPath.push(Directions::North);
        } else if (previous[i / columns][i % columns] == i + columns) {
            robotPath.push(Directions::South);
        }
    }
    while (!robotPath.isEmpty()) {
        switch (robotPath.pop()) {
            case Directions::North:
                std::cout << "North ";
                break;
            case Directions::East:
                std::cout << "East ";
                break;
            case Directions::West:
                std::cout << "West ";
                break;
            case Directions::South:
                std::cout << "South ";
                break;
        }
    }

    deallocateMatrix(matrix, rows);
    return 0;
}