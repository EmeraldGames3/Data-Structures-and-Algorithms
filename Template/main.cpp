#include <iostream>
#include "DynamicArray/DynamicArray.cpp"

int main() {
    // create a dynamic array of integers
    DynamicArray<int> arr1;

    // append some elements to the array
    arr1.addToEnd(5);
    arr1.addToEnd(10);
    arr1.addToEnd(15);

    // print the array
    std::cout << "arr1: ";
    arr1.printArray();  // expected output: [5, 10, 15]

    // get the length of the array
    std::cout << "arr1 length: " << arr1.size() << std::endl;  // expected output: 3

    // get the capacity of the array
    std::cout << "arr1 capacity: " << arr1.getCapacity() << std::endl;  // expected output: 10

    // resize the array
    arr1.resize(5);
    std::cout << "arr1 after resizing: ";
    arr1.printArray();  // expected output: [5, 10, 15, 0, 0]

    // access an element in the array
    std::cout << "arr1[1]: " << arr1[1] << std::endl;  // expected output: 10

    // modify an element in the array
    arr1[2] = 20;
    std::cout << "arr1 after modification: ";
    arr1.printArray();  // expected output: [5, 10, 20, 0, 0]

    // create a copy of the array
    DynamicArray<int> arr2 = arr1;

    // print the copy
    std::cout << "arr2: ";
    arr2.printArray();  // expected output: [5, 10, 20, 0, 0]

    // add two arrays together
    DynamicArray<int> arr3 = arr1 + arr2;
    std::cout << "arr3: ";
    arr3.printArray();  // expected output: [5, 10, 20, 0, 0, 5, 10, 20, 0, 0]

    // compare two arrays
    std::cout << "arr1 == arr2: " << (arr1 == arr2) << std::endl;  // expected output: 1
    std::cout << "arr1 == arr3: " << (arr1 == arr3) << std::endl;  // expected output: 0

    return 0;
}
