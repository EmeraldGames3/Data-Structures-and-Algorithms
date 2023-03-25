#pragma once
#include "../LocationQueue/LocationQueue.h"

enum MazeSymbol {
    Wall = 'X',
    Robot = 'R',
    Path = '*',
    Goal = 'G',
    Visited = 'V',
    Empty = ' '
};

void solveMaze(char **matrix, int rows, int columns);