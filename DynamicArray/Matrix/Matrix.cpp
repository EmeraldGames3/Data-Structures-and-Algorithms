#include "Matrix.h"
#include <exception>
#include <iostream>

using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {

    //TODO - Implementation
    nrRow = nrLines;
    nrCol = nrCols;
    size = 0;
    capacity = 99999;
    row = new int[capacity];
    column = new int[capacity];
    value = new TElem[capacity];
}


int Matrix::nrLines() const {
    //TODO - Implementation
    return nrRow;
}


int Matrix::nrColumns() const {
    //TODO - Implementation
    return nrCol;
}


TElem Matrix::element(int i, int j) const {
    //TODO - Implementation
    if (i < 0 || j < 0 || i >= nrRow || j >= nrCol)
        throw invalid_argument("");
    for (int index = 0; index < size; index++) {
        if (row[index] == i && column[index] == j) {
            return value[index];
        }
    }
    return NULL_TELEM;
}

void Matrix::remove(int index) {
    for (int i = index; i < size - 1; i++) {
        row[i] = row[i + 1];
        column[i] = column[i + 1];
        value[i] = value[i + 1];
    }
    size--;
}

int Matrix::findPosition(int position) {
    int left = 0;
    int right = size - 1;
    int mid;
    while(left<right){
        mid = (left+right)/2;
       if(row[mid] == position)
       {
           left = mid;
           break;
       }
       else if(row[mid] > position){
           right = mid - 1;

       } else
       {
           left = mid+1;

       }
    }
    return left;
}

TElem Matrix::modify(int i, int j, TElem e) {
    //TODO - Implementation
    if (i < 0 || j < 0 || i >= nrRow || j >= nrCol)
        throw invalid_argument("");

    if (size == 0 && e != 0) {
        row[size] = i;
        column[size] = j;
        value[size] = e;
        size++;
        return NULL_TELEM;
    }
    for (int index = 0; index < size; index++){
        if(row[index] == i && column[index] == j){
            TElem elem = value[index];
            if(e == 0){
                remove(index);
                return elem;
            }
            value[index] = e;
            return elem;

        }
    }
    if(e == 0)
        return NULL_TELEM;
    int position = findPosition(i);
    for(int index = size; index> position;index--){
        value[index] = value[index - 1];
        row[index] = row[index - 1];
        column[index] = column[index -1];
    }
    value[position] = e;
    row[position] = i;
    column[position] = j;
    size++;
    return NULL_TELEM;
}

Matrix::~Matrix() {
    //TODO - Implementation
    delete[] row;
    delete[] column;
    delete[] value;
}


