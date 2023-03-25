#include <exception>
#include "Location.h"

/**
 * @brief Constructor with implicit parameters
 * @details The implicit value of a Location is row = -1 and column = -1 which is an invalid Location
 **/
Location::Location(int i, int j) : row(i), column(j) {}

/**
 * @brief Copy constructor
 **/
Location::Location(Location &location) : row(location.getRow()), column(location.getColumn()){}

/**
 * @brief Getters
 **/
int Location::getRow() const {return row;}
int Location::getColumn() const {return column;}

/**
 * @brief Setters
 **/
void Location::setRow(int newRow) {
    if(newRow < -1)
        throw std::exception();
    this->row = newRow;
}
void Location::setColumn(int newColumn) {
    if(newColumn < -1)
        throw std::exception();
    this->column = newColumn;
}

/**
 * @brief Overload the == operator
 **/
bool Location::operator==(const Location &otherLocation) const {
    return this->row == otherLocation.getRow() && this->column == otherLocation.getColumn();
}

/**
 * Destructor
 **/
Location::~Location() = default;