#include <iostream>
#include "Robot.h"
#include "RobotSetup.h"

void solveMaze(char **matrix, int rows, int columns) {
    // Find the starting location of the robot
    Location start = findRobot(matrix, rows, columns);
    if (start.getRow() == -1 && start.getColumn() == -1) {
        std::cout << "Robot not found in the maze!" << std::endl;
        return;
    }

    int goalsNumber;
    setGoal(matrix, rows, columns, goalsNumber);
    Location *goals = findGoals(matrix, rows, columns, goalsNumber);

//     Create a queue to perform breadth-first search
//    std::queue<Location> queue;
//    queue.push(start);


    // Create a visited matrix to keep track of visited locations
//    bool **visited = new bool*[rows];
//    for (int i = 0; i < rows; i++) {
//        visited[i] = new bool[columns];
//        for (int j = 0; j < columns; j++) {
//            visited[i][j] = false;
//        }
//    }


//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < columns; j++) {
//            std::cout << visited[i][j] << ' ';
//        }
//        std::cout << "\n";
//    }
//
//    std::cout << "\n";

//    while (!queue.empty()) {
//        // Get the next location from the queue
//        Location current = queue.front();
//        queue.pop();
//
//        // Check if the current location is a goal
//        if (matrix[current.getRow()][current.getColumn()] == MazeSymbol::Goal) {
//            std::cout << "Robot found a goal at: " << current.getRow() << ' ' << current.getColumn() << std::endl;
//            break;
//        }
//
//        // Mark the current location as visited
//        visited[current.getRow()][current.getColumn()] = true;
//
//        // Check all adjacent locations
//        std::pair<int, int> directions[] = {{-1, 0},
//                                            {1,  0},
//                                            {0,  -1},
//                                            {0,  1}};
//        for (auto &dir: directions) {
//            int newRow = current.getRow() + dir.first;
//            int newColumn = current.getColumn() + dir.second;
//
//            // Check if the new location is valid and not a wall or already visited
//            if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns &&
//                !visited[newRow][newColumn] && matrix[newRow][newColumn] != MazeSymbol::Wall) {
//                // Add the new location to the queue
//                queue.emplace(newRow, newColumn);
//                visited[newRow][newColumn] = true;
//            }
//        }
//    }

    std::cout<<"It Works\n";

    // Free dynamically allocated memory
//    for (int i = 0; i < rows; i++) {
//        delete[] visited[i];
//    }
//    delete[] visited;
    delete[] goals;
}
