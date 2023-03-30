#include "SolveLabyrinth.h"

Location::Location() : row(-1), column(-1) {}

Location::Location(int i, int j) : row(i), column(j) {}

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

int getLinearIndex(int i, int j, int columns) {
    return (i - 1) * columns + j;
}

Location findPositionOfLinearIndex(TElem linearIndex, int columns) {
    int row = (linearIndex - 1) / columns + 1;
    int col = (linearIndex - 1) % columns + 1;
    return {row, col};
}

//Returns false if the labyrinth has no exit
//Changes pointOfExit to the coordinates where the robot exits the labyrinth
bool breadthFirstSearch(char **matrix, Location robotLocation, int rows, int columns, short **previous,
                        Location &pointOfExit) {
    auto queue = Queue();
    queue.push(getLinearIndex(robotLocation.row, robotLocation.column, columns));

    previous[robotLocation.row][robotLocation.column] = RobotPosition;
    while (!queue.isEmpty()) {
        int currentLinearIndex = queue.pop();
        Location currentLocation = findPositionOfLinearIndex(currentLinearIndex, columns);
        int i = currentLocation.row;
        int j = currentLocation.column;
        matrix[robotLocation.row][robotLocation.column] = Robot;

        if (i > 0 && matrix[i - 1][j] != Visited && matrix[i - 1][j] != Wall) {
            if (matrix[i - 1][j] == Goal) {
                pointOfExit = Location(i - 1, j);
                matrix[i - 1][j] = Visited;
                printMatrix(matrix, rows, columns);
                previous[i - 1][j] = South;
                return true;
            }
            matrix[i - 1][j] = Visited;
            previous[i - 1][j] = South;
            queue.push(currentLinearIndex - columns);
        }
        if (i < rows - 1 && matrix[i + 1][j] != Visited && matrix[i + 1][j] != Wall) {
            if (matrix[i + 1][j] == Goal) {
                pointOfExit = Location(i + 1, j);
                matrix[i + 1][j] = Visited;
                printMatrix(matrix, rows, columns);
                previous[i + 1][j] = North;
                return true;
            }
            matrix[i + 1][j] = Visited;
            previous[i + 1][j] = North;
            queue.push(currentLinearIndex + columns);
        }
        if (j > 0 && matrix[i][j - 1] != Visited && matrix[i][j - 1] != Wall) {
            if (matrix[i][j - 1] == Goal) {
                pointOfExit = Location(i, j - 1);
                matrix[i][j - 1] = Visited;
                printMatrix(matrix, rows, columns);
                previous[i][j - 1] = West;
                return true;
            }
            matrix[i][j - 1] = Visited;
            previous[i][j - 1] = West;
            queue.push(currentLinearIndex - 1);
        }
        if (j < columns - 1 && matrix[i][j + 1] != Visited && matrix[i][j + 1] != Wall) {
            if (matrix[i][j + 1] == Goal) {
                pointOfExit = Location(i, j + 1);
                matrix[i][j + 1] = Visited;
                printMatrix(matrix, rows, columns);
                previous[i][j + 1] = East;
                return true;
            }
            matrix[i][j + 1] = Visited;
            previous[i][j + 1] = East;
            queue.push(currentLinearIndex + 1);
        }
        printMatrix(matrix, rows, columns);
    }
    return false;
}

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