#include <iostream>
#include "Tests/TestAllFunctionalities.h"
#include "IO/IO.h"
#include "Robot/Robot.h"

using namespace std;

int main() {
    testAllFunctionalities();
//    cin.get();

    int rows = 0;
    int columns = 0;
    char **matrix = readMatrixFromFile("IO/input.txt", rows, columns);

    printMatrix(matrix, rows, columns);
    std::cout<<'\n';

    solveMaze(matrix, rows, columns);

    deallocateMatrix(matrix, rows);

    return 0;
}