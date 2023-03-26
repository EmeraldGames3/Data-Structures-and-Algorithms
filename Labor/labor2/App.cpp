#include <iostream>
#include "Queue/Queue.h"
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

void solveLabyrinth(char **matrix, int rows, int columns, float **distances, char **path) {

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