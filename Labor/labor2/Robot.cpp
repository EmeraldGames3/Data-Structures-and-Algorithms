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