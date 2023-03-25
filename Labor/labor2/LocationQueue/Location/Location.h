#pragma once

class Location {
private:
    int row;
    int column;

public:
    static Location InvalidLocation();

    //Constructor with implicit parameters
    explicit Location(int i = -1, int j = -1);

    //Copy constructor
    Location(Location &location);

    //Getters
    [[nodiscard]] int getRow() const;
    [[nodiscard]] int getColumn() const;

    //Setters
    void setRow(int newRow);
    void setColumn(int newColumn);

    //Destructor
    ~Location();

    //Overloaded operators
    bool operator==(const Location &otherLocation) const;
    Location &operator=(const Location &other);
};