#include "RobotSetup.h"

Location findRobot(char **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] == MazeSymbol::Robot) {
                return Location(i, j); // Location of the Robot
            }
        }
    }
    return Location::InvalidLocation(); // Robot is not in the Labyrinth
}

void setGoal(char **matrix, int rows, int columns, int &goalNumber) {
    goalNumber = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if ((i == 0 || j == 0 || i == rows - 1 || j == columns - 1) && matrix[i][j] == MazeSymbol::Path) {
                matrix[i][j] = MazeSymbol::Goal;
                goalNumber++;
            }
        }
    }
}

Location *findGoals(char **matrix, int rows, int columns, int goalsNumber) {
    auto *goals = new Location[goalsNumber];
    int goalsIndex = 0;

    for (int i = 0; i < rows; i++)
        if (matrix[i][0] == MazeSymbol::Goal) {
            goals[goalsIndex] = Location(i, 0);
            goalsIndex++;
        }
    for (int i = 0; i < rows; i++)
        if (matrix[i][columns - 1] == MazeSymbol::Goal) {
            goals[goalsIndex] = Location(i, columns - 1);
            goalsIndex++;
        }
    for (int j = 0; j < columns; j++)
        if (matrix[0][j] == MazeSymbol::Goal) {
            goals[goalsIndex] = Location(0, j);
            goalsIndex++;
        }
    for (int j = 0; j < columns; j++)
        if (matrix[rows - 1][j] == MazeSymbol::Goal) {
            goals[goalsIndex] = Location(rows - 1, j);
            goalsIndex++;
        }

    return goals;
}