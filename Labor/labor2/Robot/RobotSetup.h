#pragma once

#include "../LocationQueue/Location/Location.h"
#include "Robot.h"

Location findRobot(char **matrix, int rows, int columns);

void setGoal(char **matrix, int rows, int columns, int &goalNumber);

Location *findGoals(char **matrix, int rows, int columns, int goalsNumber);