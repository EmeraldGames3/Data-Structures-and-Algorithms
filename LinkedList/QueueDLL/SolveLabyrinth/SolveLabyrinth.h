#pragma once

#include "../Queue/Queue.h"
#include "../IO/IO.h"
#include <iostream>
#include "../Stack/Stack.h"

enum Directions {
    Invalid = -1,
    RobotPosition = 0,
    North = 1,
    South = 2,
    West = 3,
    East = 4,
};

struct Location {
    int row;
    int column;

    explicit Location();

    Location(int i, int j);
};

Location findRobot(char **matrix, int rows, int columns);

bool exitExists(char **matrix, int rows, int columns);

int getLinearIndex(int i, int j, int columns);

Location findPositionOfLinearIndex(TElem linearIndex, int columns);

bool breadthFirstSearch(char **matrix, Location robotLocation, int rows, int columns, short **previous,
                        Location &pointOfExit);

void printShortestPath(short **previous, Location robotLocation, Location pointOfExit);