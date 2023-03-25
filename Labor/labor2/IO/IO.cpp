#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

void printMatrix(char **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}


void deallocateMatrix(char **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
