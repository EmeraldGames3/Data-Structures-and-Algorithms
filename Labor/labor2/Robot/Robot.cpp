#include <iostream>
#include "Robot.h"

Location findRobot(char **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] == 'R') {
                return Location(i, j); // Location of the Robot
            }
        }
    }
    return Location(); // Robot is not in the Labyrinth
}

Location *findValidNeighbours(Location &location, char **matrix, int rows, int columns, int &neighborsNumber) {
    auto *neighbours = new Location[4];
    int count = 0;
    int row = location.getRow();
    int column = location.getColumn();

    //Check North neighbour
    if (row > 0 && matrix[row - 1][column] != 'X') {
        neighbours[count] = Location(row - 1, column);
        count++;
    }

    //Check West neighbour
    if (column > 0 && matrix[row][column - 1] != 'X') {
        neighbours[count] = Location(row, column - 1);
        count++;
    }

    //Check East neighbour
    if (column < columns - 1 && matrix[row][column + 1] != 'X') {
        neighbours[count] = Location(row, column + 1);
        count++;
    }

    //Check South neighbour
    if (row < rows - 1 && matrix[row + 1][column] != 'X') {
        neighbours[count] = Location(row + 1, column);
        count++;
    }

    //If there are no valid neighbours, return nullptr
    if (count == 0) {
        delete[] neighbours;
        return nullptr;
    }

    //Resize the array to the exact number of valid neighbours
    auto *result = new Location[count];
    neighborsNumber = count;
    for (int i = 0; i < count; i++) {
        result[i] = neighbours[i];
    }

    delete[] neighbours;

    return result;
}

Location findGoal(char **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] == 'G') {
                return Location(i, j);
            }
        }
    }
    return Location(-1, -1); // Goal not found
}

void printPath(const LocationQueue &path) {
    if (path.isEmpty()) {
        std::cout << "No path to the goal was found.\n";
        return;
    }

    // Create a copy of the original path so we don't modify it
    LocationQueue copy = path;

    // Remove the first location (the robot's location) from the copy
    copy.pop();

    // Check if the copy is empty, meaning the robot is already at the goal
    if (copy.isEmpty()) {
        std::cout << "The robot is already at the goal.\n";
        return;
    }

    // Print the path from the robot to the goal
    std::cout << "Path from robot to goal: ";
    while (!copy.isEmpty()) {
        Location location = copy.pop();
        std::cout << "(" << location.getRow() << "," << location.getColumn() << ")";
        if (!copy.isEmpty()) {
            std::cout << " -> ";
        }
    }
    std::cout << "\n";
}
//
//void solveMaze(char **matrix, int rows, int columns) {
//    if (findGoal(matrix, rows, columns) == Location::InvalidLocation()) {
//        std::cout << "No valid path found to the goal.\n";
//        return;
//    }
//
//    // Find the robot's starting location
//    Location robotLocation = findRobot(matrix, rows, columns);
//
//    // Create a queue to store the locations to visit
//    LocationQueue locationsToVisit;
//    locationsToVisit.push(robotLocation);
//
//    // Mark the robot's starting location as visited
//    matrix[robotLocation.getRow()][robotLocation.getColumn()] = MazeSymbol::Visited;
//
//    while (!locationsToVisit.isEmpty()) {
//        // Get the next location to visit
//        Location currentLocation = locationsToVisit.pop();
//
//        // If we reached the goal, print the path and return
//        if (matrix[currentLocation.getRow()][currentLocation.getColumn()] == MazeSymbol::Goal) {
//            std::cout << "Path found from Robot to Goal:\n";
//            LocationQueue path = buildPath(matrix, rows, columns, robotLocation, currentLocation);
//            printPath(path);
//            return;
//        }
//
//        // Find the valid neighbours of the current location
//        int neighborsNumber = 0;
//        Location *neighbours = findValidNeighbours(currentLocation, matrix, rows, columns, neighborsNumber);
//
//        // Mark the current location as visited
//        matrix[currentLocation.getRow()][currentLocation.getColumn()] = MazeSymbol::Visited;
//
//        // Add the valid neighbours to the queue
//        for (int i = 0; i < neighborsNumber; i++) {
//            if (matrix[neighbours[i].getRow()][neighbours[i].getColumn()] != MazeSymbol::Visited) {
//                locationsToVisit.push(neighbours[i]);
//
//                // Mark the neighbour as visited
//                matrix[neighbours[i].getRow()][neighbours[i].getColumn()] = MazeSymbol::Visited;
//
//                // Mark the neighbour's parent as the current location
//                matrix[neighbours[i].getRow()][neighbours[i].getColumn()] = getDirectionChar(
//                        currentLocation.getDirectionTo(neighbours[i]));
//            }
//        }
//
//        delete[] neighbours;
//    }
//
//    // If we reach this point, there is no path from the robot to the goal
//    std::cout << "No valid path found to the goal.\n";
//}
