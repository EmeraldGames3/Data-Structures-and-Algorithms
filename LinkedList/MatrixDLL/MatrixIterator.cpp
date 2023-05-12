#include <exception>
#include "MatrixIterator.h"
#include "Matrix.h"

using namespace std;

/**descr: initializes elements that are used in the following methods
   pre: m e Matrix
   post: intializes i and j indexes with 0
   Time Complexity: Best Case: Θ(1)
                    Worst Case: Θ(1)
                    Average Case: Θ(1)*/
MatrixIterator::MatrixIterator(const Matrix& m): matrix(m)
{
	//TODO - Implementation
    this->i = 0;
    this->j = 0;
}

/**descr: it reinitializes i and j indexes with 0
   pre: i,j e Matrix
   post: i and j will be set to 0
   Time Complexity: Best Case: Θ(1)
                    Worst Case: Θ(1)
                    Average Case: Θ(1)*/
void MatrixIterator::first() {
	//TODO - Implementation
    i = 0;
    j = 0;
}

/**descr: it increments the row index
   pre: i e Matrix
   post: row index will be incremented
   throws: an exception, if after the incrementation, the row index will be out of bounds
   Time Complexity: Best Case: Θ(1)
                    Worst Case: Θ(1)
                    Average Case: Θ(1)*/
void MatrixIterator::next_i() {
	//TODO - Implementation
    if (!valid()){
        throw exception();
    }
    else{
        if (i < matrix.nrLines()){
            i++;
        }
        else{
            throw exception();
        }
    }
}

/**descr: it increments the column index
   pre: j e Matrix
   post: column index will be incremented
   throws: an exception, if after the incrementation, the column index will be out of bounds
   Time Complexity: Best Case: Θ(1)
                    Worst Case: Θ(1)
                    Average Case: Θ(1)*/
void MatrixIterator::next_j() {
    //TODO - Implementation
    if (!valid()){
        throw exception();
    }
    else{
        if (j < matrix.nrColumns()){
            j++;
        }
        else{
            throw exception();
        }
    }
}

/**descr: it checks if the indexes are in or out of bounds
   pre: i,j e Matrix
   post: true if i, j are in bounds; false if i, j are out of bounds
   Time Complexity: Best Case: Θ(1)
                    Worst Case: Θ(1)
                    Average Case: Θ(1)*/
bool MatrixIterator::valid() const {
	//TODO - Implementation
	if ((i < 0 || i > matrix.nrLines()) || (j < 0 || j > matrix.nrColumns()))
        return false;
    return true;
}

/**descr: it returns the element at current indexes
   pre: i,j e Matrix
   post: element from current indexes will be returned
   throws: an exception, if the indexes are out of bounds (not valid)
   Time Complexity: Best Case: Θ(1)
                    Worst Case: Θ(1)
                    Average Case: Θ(1)*/
TElem MatrixIterator::getCurrent() const
{
	//TODO - Implementation
    if (!valid()){
        throw exception();
    }
    else{
        return matrix.element(i, j);
    }
}
