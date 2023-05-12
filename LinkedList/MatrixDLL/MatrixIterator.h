#include "Matrix.h"

class MatrixIterator
{
	//DO NOT CHANGE THIS PART
	friend class Matrix;
	
private:
	const Matrix& matrix;
    int i;
    int j;
public:
    MatrixIterator(const Matrix& m);
	void first();
	void next_i();
    void next_j();
	TElem getCurrent() const;
	bool valid() const;
};
