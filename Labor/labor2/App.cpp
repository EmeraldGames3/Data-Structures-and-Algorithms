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

enum Directions {
    North = 0,
    South = 1,
    West = 2,
    East = 3
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

int getLinearIndex(int i, int j, int columns){
    return (i-1) * columns + j;
}

Location findPositionOfLinearIndex(TElem linearIndex, int columns){
    int row = (linearIndex-1) / columns + 1;
    int col = (linearIndex-1) % columns + 1;
    return {row, col};
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
    
    auto queue = Queue();
    queue.push(getLinearIndex(robotLocation.row, robotLocation.column, columns));

    while(!queue.isEmpty()){
        int currentLinearIndex = queue.pop();
        Location currentLocation = findPositionOfLinearIndex(currentLinearIndex, columns);
        int i = currentLocation.row;
        int j = currentLocation.column;
        matrix[robotLocation.row][robotLocation.column] = Robot;

        if (i > 0 && matrix[i - 1][j] != Visited && matrix[i - 1][j] != Wall){
            if(matrix[i - 1][j] == Goal){
                std::cout << "Labyrinth solved\n";
                matrix[i- 1][j] = Visited;
                printMatrix(matrix, rows, columns);
                break;
            }
            matrix[i- 1][j] = Visited;
            queue.push(currentLinearIndex - columns);
        }
        if (i < rows - 1 && matrix[i + 1][j] != Visited && matrix[i + 1][j] != Wall){
            if(matrix[i + 1][j] == Goal){
                std::cout << "Labyrinth solved\n";
                matrix[i + 1][j] = Visited;
                printMatrix(matrix, rows, columns);
                break;
            }
            matrix[i + 1][j] = Visited;
            queue.push(currentLinearIndex + columns);
        }
        if (j > 0 && matrix[i][j - 1] != Visited && matrix[i][j - 1] != Wall){
            if(matrix[i][j - 1] == Goal){
                std::cout << "Labyrinth solved\n";
                matrix[i][j - 1] = Visited;
                printMatrix(matrix, rows, columns);
                break;
            }
            matrix[i][j - 1] = Visited;
            queue.push(currentLinearIndex - 1);
        }
        if (j < columns - 1 && matrix[i][j + 1] != Visited && matrix[i][j + 1] != Wall) {
            if(matrix[i][j + 1] == Goal){
                std::cout << "Labyrinth solved\n";
                matrix[i][j + 1] = Visited;
                printMatrix(matrix, rows, columns);
                break;
            }
            matrix[i][j + 1] = Visited;
            queue.push(currentLinearIndex + 1);
        }
        printMatrix(matrix, rows, columns);
    }

    if(queue.isEmpty()){
        std::cout << "The labyrinth has no exit\n";
        return 0;
    }

    deallocateMatrix(matrix, rows);
    return 0;
}
