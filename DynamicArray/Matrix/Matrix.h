#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

class Matrix {

private:
	//TODO - Representation
    int *row;
    int nrRow;
    int nrCol;
    int *column;
    TElem *value;
    int size;
    int capacity;
public:
	//constructor
	Matrix(int nrLines, int nrCols);
    int findPosition(int position);
    void remove(int index);
	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);
	
	// destructor
	~Matrix();

};
