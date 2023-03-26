#include <iostream>
#include <queue>
#include "IO/IO.h"
#include "Queue/QueueTest/ExtendedTest.h"
#include "Queue/QueueTest/ShortTest.h"

using namespace std;

enum Directions {
    North,
    South,
    West,
    East
};

void printMatrixWithPathAndDirections(char **matrix, char **path, int rows, int columns) {
    cout << endl << "MATRIX WITH PATH:" << endl << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (path[i][j] == '*') {
                cout << "P ";
            } else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}


void solveLabyrinth(char **matrix, int rows, int columns, float **distances, char **path) {
    // Define queue to hold positions
    queue <pair<int, int>> positions;

    // Define the initial position
    int start_row = 4;
    int start_column = 4;

    // Add the initial position to the queue
    positions.push({start_row, start_column});

    // Define the goal position
//    pair<int, int> goal_position = getGoalPosition(matrix, rows, columns);
    pair<int, int> goal_position = make_pair(4, 4);

    // Define the directions
    pair<int, int> directions[] = {{-1, 0},
                                   {1,  0},
                                   {0,  -1},
                                   {0,  1}};
    char direction_labels[] = {'N', 'S', 'W', 'E'};

    // Perform breadth-first search to find the shortest path
    while (!positions.empty()) {
        // Get the current position
        pair<int, int> current_position = positions.front();
        positions.pop();

        // Check if the current position is the goal position
        if (current_position == goal_position) {
            break;
        }

        // Check the neighboring positions
        for (int i = 0; i < 4; i++) {
            // Get the neighboring position
            pair<int, int> neighbor_position = {current_position.first + directions[i].first,
                                                current_position.second + directions[i].second};

            // Check if the neighbor position is inside the matrix boundaries and it's not a wall
            if (neighbor_position.first >= 0 && neighbor_position.first < rows &&
                neighbor_position.second >= 0 && neighbor_position.second < columns &&
                matrix[neighbor_position.first][neighbor_position.second] != 'X') {
                // Calculate the new distance to the neighbor
                float new_distance = distances[current_position.first][current_position.second] + 1;

                // Update the distances if the new distance is shorter
                if (new_distance < distances[neighbor_position.first][neighbor_position.second]) {
                    distances[neighbor_position.first][neighbor_position.second] = new_distance;
                    path[neighbor_position.first][neighbor_position.second] = direction_labels[i];
                    positions.push(neighbor_position);
                }
            }
        }
    }

    // Print the path
    printMatrixWithPathAndDirections(matrix, path, rows, columns);
}


int main() {
    testAll();
    testAllExtended();
//    cin.get();

    int rows = 0;
    int columns = 0;
    auto **matrix = readMatrixFromFile("IO/input.txt", rows, columns);

    auto **distances = new float *[rows];
    auto **path = new char *[rows];

    // Allocate memory for distances and path
    for (int i = 0; i < rows; i++) {
        distances[i] = new float[columns];
        path[i] = new char[columns];
    }

    // Initialize distances to FLT_MAX and path to ' '
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            distances[i][j] = (float) INT16_MAX;
            path[i][j] = ' ';
        }
    }

    // Set the distance of the starting point to 0
    distances[4][4] = 0.0;

    printMatrix(matrix, rows, columns);

    setGoal(matrix, rows, columns);
    solveLabyrinth(matrix, rows, columns, distances, path);

    printMatrix(matrix, rows, columns);

    // Free memory for distances and path
    for (int i = 0; i < rows; i++) {
        delete[] distances[i];
        delete[] path[i];
    }
    delete[] distances;
    delete[] path;
    deallocateMatrix(matrix, rows);

    return 0;
}