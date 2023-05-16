#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "IO.h"

/**
 * Read the matrix from the file
 * @complexityΩ θ(n^2)
 * @complexityθ θ(n^2)
 * @complexityO θ(n^2)
 */
char **readMatrixFromFile(const char *fileName, int &rows, int &columns) {
    std::ifstream inputFile(fileName);
    std::string line;
    char **matrix;

    // Read the number of rows and columns in the matrix
    if (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        ss >> rows >> columns;
    }

    // Allocate memory for the matrix
    matrix = new char *[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new char[columns];
    }

    // Read the matrix elements from the input file
    for (int i = 0; i < rows; i++) {
        if (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            for (int j = 0; j < columns; j++) {
                ss >> matrix[i][j];
            }
        }
    }

    // Return the matrix
    return matrix;
}

/**
* Print the matrix
* @complexityΩ θ(n^2)
* @complexityθ θ(n^2)
* @complexityO θ(n^2)
 */
void printMatrix(char **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

/**
* Set the goals that have to be reaches
* @complexityΩ θ(n)
* @complexityθ θ(n)
* @complexityO θ(n)
 */
void setGoal(char **matrix, int rows, int columns) {

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == '*')
            matrix[i][0] = 'G';
        if (matrix[i][columns - 1] == '*')
            matrix[i][columns - 1] = 'G';
    }

    for (int j = 0; j < columns; j++) {
        if (matrix[0][j] == '*')
            matrix[0][j] = 'G';
        if (matrix[rows - 1][j] == '*')
            matrix[rows - 1][j] = 'G';
    }

//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < columns; j++) {
//            if ((i == 0 || j == 0 || i == rows - 1 || j == columns - 1) && matrix[i][j] == '*') {
//                matrix[i][j] = 'G';
//            }
//        }
//    }
}

/**
* Delete the dynamically allocated matrix
* @complexityΩ θ(n^2)
* @complexityθ θ(n^2)
* @complexityO θ(n^2)
 */
void deallocateMatrix(char **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}