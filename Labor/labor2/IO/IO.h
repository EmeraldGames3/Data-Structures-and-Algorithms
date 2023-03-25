#pragma once

char **readMatrixFromFile(const char *fileName, int &rows, int &columns);

void deallocateMatrix(char **matrix, int rows, int columns);

void printMatrix(char **matrix, int rows, int columns);