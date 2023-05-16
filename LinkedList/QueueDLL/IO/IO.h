#pragma once

enum MatrixStates {
    Wall = 'X',
    Robot = 'R',
    Visited = 'V',
    Path = '*',
    Goal = 'G',
};

char **readMatrixFromFile(const char *fileName, int &rows, int &columns);

void deallocateMatrix(char **matrix, int rows);

void setGoal(char **matrix, int rows, int columns);

void printMatrix(char **matrix, int rows, int columns);