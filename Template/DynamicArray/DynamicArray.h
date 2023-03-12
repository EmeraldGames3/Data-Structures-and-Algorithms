#include <iostream>

#pragma once

template<typename type>
class DynamicArray {

private:
    type *array;
    size_t length{};
    size_t capacity{};

    //Automatically resize the array
    void automaticResize();

    //Check if an index is valid
    bool inRange(size_t index);

public:
    //constructor with 0 parameters
    explicit DynamicArray();

    //constructor with 1 parameter
    explicit DynamicArray(size_t _length);

    //constructor with 2 parameters
    DynamicArray(size_t _length, type *array);

    //constructor with 3 parameters
    DynamicArray(size_t _length, size_t _capacity, type *array);

    //constructor for creating an exact copy of the dynamic array
    DynamicArray(const DynamicArray<type> &other);

    //Class destructor
    ~DynamicArray();

    //Overload the '[]' operator
    int &operator[](int index) {
        if (index < 0 || index >= length)throw std::out_of_range("Index out of range");
        return array[index];
    }

    //Overload the '=' operator
    DynamicArray<type> &operator=(const DynamicArray<type> &other) {
        if (this != &other) {
            delete[] array; // deallocate current memory
            length = other.length;
            capacity = other.capacity;
            array = new type[capacity];

            for (size_t i = 0; i < length; i++)
                array[i] = other.array[i];
        }

        return *this;
    }

//Overload the '+' operator
    DynamicArray<type> operator+(const DynamicArray<type> &other) {
        size_t newLength = this->length + other.length;
        size_t newCapacity = this->capacity + other.capacity;
        type *newArray = new type[newCapacity];

        for (size_t i = 0; i < this->length; i++)
            newArray[i] = this->array[i];

        for (size_t i = 0; i < other.length; i++)
            newArray[i + length] = other.array[i];

        DynamicArray<type> result(newLength, newCapacity, newArray);
        delete[] newArray; //deallocate memory
        return result;
    }

    //Overload the '==' operator
    bool operator==(const DynamicArray<type> &other) const{
        if(this->length != other.length) return false;

        DynamicArray<type> copyOfThis = DynamicArray<type>(length, capacity, array);
        DynamicArray<type> copyOfOther = DynamicArray<type>(other);

        copyOfOther.sortArray();
        copyOfThis.sortArray();

        for(int i = 0; i < length; i++)
            if(copyOfThis[i] != copyOfOther[i])
                return false;

        return true;
    }

    //Return the size of the array
    size_t size();

    //Return the current capacity of the array
    size_t getCapacity();

    //Resize the array
    void resize(size_t newCapacity);

    //Get an element from the array
    type getElement(size_t index);

    //Change the value of an element in the array
    void setElement(size_t index, type value);

    //Add an element to the end of the array
    void addToEnd(type value);

    //Add an element to a specific position
    void addToPosition(size_t index, type value);

    //Delete an element from the end of the array
    void deleteFromEnd();

    //Delete the element from a specific position in the array
    void deleteFromPosition(size_t index);

    //Sort the array
    void sortArray(bool reverse = false);

    //Print the array in the console
    void printArray();
};