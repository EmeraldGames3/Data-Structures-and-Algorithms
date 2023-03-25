#include "Queue/Queue.h"
#include "Queue/QueueTest/ExtendedTest.h"
#include "Queue/QueueTest/ShortTest.h"
#include <iostream>
#include "RobotInLabyrinth.h"

using namespace std;

int main() {
	testAll();
	testAllExtended();
    cin.get();

    int rows{}, columns{};
    char **matrix;
    const char *fileName = "input.txt";
    readMatrixFromFile(rows, columns, fileName);
}